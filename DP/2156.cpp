#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int arr[10001];
int dp[10001][3];
int main()
{
  int n;
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
    {
      cin>>arr[i];
    }

  dp[1][1]=arr[1];
  dp[2][0]=arr[1];
  dp[2][1]=arr[2];
  dp[2][2]=arr[1]+arr[2];

  for(int i=3;i<=n;i++)
  {
    dp[i][0]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
    dp[i][1]= dp[i-1][0]+arr[i];
    dp[i][2]=dp[i-1][1]+arr[i];
  }
    
    cout<<max({dp[n][0],dp[n][1],dp[n][2]});



}