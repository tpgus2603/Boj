#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 100000000

using namespace std;

int dp[401][401];
int cycle[401][410];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int v,e;
  cin>>v>>e;
  for(int i=1;i<=v;i++)
  {
    for(int j=1;j<=v;j++)
    {
      if(i==j)
        dp[i][j]=0;
      else
        dp[i][j]=MAX;
    }
  }
  int a,b,c;
  for(int i=1;i<=e;i++)
  {
    cin>>a>>b>>c;
    dp[a][b]=c;
  }
  for(int k=1;k<=v;k++)
  {
    for(int i=1;i<=v;i++)
    {
      for(int j=1;j<=v;j++)
      {
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
      }
    }
  }
  int mi=MAX;
  for(int i=1;i<=v;i++)
  {
    for(int j=1;j<=v;j++)
    {
      if(i==j)
        cycle[i][j]=MAX;
      else
      {
        cycle[i][j]=dp[i][j]+dp[j][i];
        mi=min(mi,cycle[i][j]);
      }
    }
  }
  if(mi==MAX)
    cout<<-1;
  else
    cout<<mi;



}