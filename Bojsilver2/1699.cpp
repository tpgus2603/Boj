#include<algorithm>
#include<iostream>
#include<math.h>

int dp[100001];

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  fill(dp,dp+n+1,100000);
  for(int i=1;i*i<=n;i++)
  {
    dp[i*i]=1;
  }
  for(int i=2;i<=n;i++)
  {
    int a=(int)sqrt(i);
    for(int j=1;j<=a;j++)
    {
      dp[i]=min(dp[i],dp[i-j*j]+dp[j*j]);
    }
  }
  cout<<dp[n];

}