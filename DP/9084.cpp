#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
  int testn;
  cin>>testn;
  while(testn--)
  {
    int n,m;
    cin>>n;
    int coin[n+1];
    for(int i=1;i<=n;i++)
      cin>>coin[i];
    cin>>m;
    int dp[n+1][m+1]={};
    for(int i=0;i<=n;i++)
      dp[i][0]=1;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(j>=coin[i])
        {
          dp[i][j]=dp[i][j-coin[i]]+dp[i-1][j];
        }
        else
          dp[i][j]=dp[i-1][j];
      }
    }
    cout<<dp[n][m]<<'\n';


  }



}