#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
int arr[100001];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  int minn=0x7fffffff;
  for(int i=0;i<n;i++)
    cin>>arr[i];
  pair<int,int> ans;
  for(int i=0;i<n;i++)
  {
    int cur=arr[i];
    int idx=lower_bound(arr,arr+n,-cur)-arr;
    if(idx<n&&idx!=i&&abs(cur+arr[idx])<minn)
    {
      ans.first=cur;
      ans.second=arr[idx];
      minn=abs(cur+arr[idx]);
    }
    if(idx!=0&&(idx-1)!=i&&abs(cur+arr[idx-1])<minn)
    {
      ans.first=cur;
      ans.second=arr[idx-1];
      minn=abs(cur+arr[idx-1]);
    }
  }
  cout<<min(ans.first,ans.second)<<' '<<max(ans.first,ans.second);

}