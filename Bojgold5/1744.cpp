#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll dp[50][2];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  vector<ll> arr(n,0);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  sort(arr.begin(),arr.end());
  dp[0][0]=arr[0];dp[0][1]=arr[0];
  for(int i=1;i<n;i++)
  {
    //dp[i][0]
    dp[i][0]=max(dp[i-1][0],dp[i-1][1])+arr[i];
    //dp[i][1]
    dp[i][1]=dp[i-1][0]+arr[i-1]*arr[i]-arr[i-1];
  }
  cout<<max(dp[n-1][0],dp[n-1][1]);

}