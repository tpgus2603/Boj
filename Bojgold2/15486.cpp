#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
#define T first 
#define P second 
int dp[1600000];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  vector<pair<int,int>>arr(n+1);
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i].T>>arr[i].P;
  }
  for(int i=1;i<=n;i++)
  {
    auto cur =arr[i];
    //cout<<i<<' '<<cur.T<<'\n';
    dp[i+cur.T-1]=max(dp[i-1]+cur.P,dp[i+cur.T-1]);
    dp[i]=max(dp[i],dp[i-1]);
    //cout<<dp[i]<<'\n';
  }
  dp[n+1]=max(dp[n],dp[n+1]);
  cout<<dp[n];

}