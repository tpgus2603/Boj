#include<iostream>
#include<algorithm>
#include<vector>

int dp1[1001]; //증가하는 수열 최대 개수에 대한 dp
int dp2[1001]; //감소하는 수열 최대 개수에 대한 dp
int dp3[1001]; // 바이토닉 수열최대 개수에 대한 dp
int arr[1001];
using namespace std;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>arr[i];
  fill(dp1,dp1+n,1);
  fill(dp2,dp2+n,1);
  for(int i=0;i<n;i++)
    for(int j=0;j<i;j++)
      if(arr[i]>arr[j])dp1[i]=max(dp1[i],dp1[j]+1);
  for(int i=n-1;i>=0;i--)
    for(int j=n-1;j>i;j--)
      if(arr[i]>arr[j])dp2[i]=max(dp2[i],dp2[j]+1);
  for(int i=0;i<n;i++)
    dp3[i]=dp1[i]+dp2[i]-1;
  int ans=*max_element(dp3,dp3+n);
  cout<<ans;

}