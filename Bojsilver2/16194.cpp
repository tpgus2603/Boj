#include<algorithm>
#include<utility>
#include<vector>
#include<iostream>

using namespace std;
int arr[1001];
int dp[1001]; //i개까지 고려했을때  최소금액 

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
  }
  dp[1]=arr[1];
  for(int i=2;i<=n;i++)
  {
    int minn=0x7fffffff;
    for(int j=1;j<=i;j++)
    {
      minn=min(minn,dp[i-j]+arr[j]);
    }
    dp[i]=minn;
  }
  cout<<dp[n];




}