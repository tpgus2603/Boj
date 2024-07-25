#include<iostream>
#include<algorithm>
#include<vector>

#define ll long long 
using namespace std;

bool cmp(ll a,ll b )
{
  return a>b;
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  vector<ll> arr;
  for(int i=0;i<n;i++)
  { 
    int temp;
    cin>>temp;
    arr.push_back(temp);
  }
  sort(arr.begin(),arr.end(),cmp);
  vector<ll> sum(n,0);
  sum[0]=arr[0];
  for(int i=1;i<n;i++)
  {
    sum[i]=sum[i-1]+arr[i];
  }
  vector<ll> dp(n,0);
  if(arr[0]-m>=0)
    dp[0]=arr[0]-m;
  ll ans;
  if(arr[0]-m>0)
    ans=arr[0]-m;
  else
    ans=0;
  for(int i=1;i<n;i++)
  {
    auto temp= (sum[i]-m)/(i+1);
    if(temp<0)
      temp=0;
    dp[i]=min(arr[i],temp);
    dp[i]=max(dp[i-1],dp[i]);
    ans=dp[i];
  }
  cout<<ans;


}