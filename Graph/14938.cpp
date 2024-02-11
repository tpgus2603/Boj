#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define MAX 10000000
int dp[101][101];
int item[101];
int cnt[101];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m,r;
  cin>>n>>m>>r;
  for(int i=1;i<=n;i++)
    cin>>item[i];
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(j==i)
        dp[i][j]=0;
      else
        dp[i][j]=MAX;
    }
  }
  int a,b,d;
  for(int i=1;i<=r;i++)
  {
    cin>>a>>b>>d;
    dp[a][b]=d;
    dp[b][a]=d;
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
  
  int max=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(dp[i][j]<=m)
        cnt[i]+=item[j];
    }
    if(cnt[i]>=max)
      max=cnt[i];
  }
  cout<<max;



}