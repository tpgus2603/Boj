#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#define MAX 100000000
using namespace std;

int dp[251][251];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(i==j)
        dp[i][j]=0;
      else
        dp[i][j]=MAX;
    }
  }
  int u,v,b;
  for(int i=1;i<=m;i++)
  {
    cin>>u>>v>>b;
    dp[u][v]=0;
    if(b==0)
      dp[v][u]=1;
    else
      dp[v][u]=0;
  }
  for(int k=1;k<=n;k++)
  {
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
      }
    }
  }
  int k;
  cin>>k;
  vector<pair<int,int>> qes;
  int t1,t2;
  for(int i=0;i<k;i++)
  {
    cin>>t1>>t2;
    cout<<dp[t1][t2]<<'\n';
  }



}

