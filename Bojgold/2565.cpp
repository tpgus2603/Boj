#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#define X first
#define Y second 
using namespace std;
int dp[101]; //마지막이 arr[i]인것중 최대
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  vector<pair<int,int>> arr;
  int n;
  cin>>n;
  int a,b;
  for(int i=0;i<n;i++)
  {
    cin>>a>>b;
    arr.push_back({a,b});
  }
  sort(arr.begin(),arr.end());
  int len=arr.size();
  dp[0]=1;
  int maxn=0;
  fill(dp,dp+len,1);
  for(int i=1;i<len;i++)
  {
    for(int j=0;j<i;j++)
    {
      if(arr[i].Y<arr[j].Y)continue;
      dp[i]=max(dp[j]+1,dp[i]);
    }
  }
  int ans;
  ans=*max_element(dp,dp+len);
  cout<<arr.size()-ans;
  


}