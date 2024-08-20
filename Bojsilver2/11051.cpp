#include<iostream>
#include<algorithm>

using namespace std;
int dp[1001][1001];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k;
  cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    dp[i][0]=1;
    dp[i][1]=i;
  }
  for(int i=2;i<=n;i++)
  {
    for(int j=2;j<=i;j++)
    {
      dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%10007;
    }
  }
  cout<<dp[n][k];

}