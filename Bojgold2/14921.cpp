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
  int left=0;
  int right=n-1;
  int ans=0;
  while(left<right)
  {
    if(abs(arr[left]+arr[right])<minn)
    {
      minn=abs(arr[left]+arr[right]);
      ans=arr[left]+arr[right];
    }
    if(abs(arr[left+1]+arr[right])<abs(arr[left]+arr[right-1]))left++;
    else right--;
  }
  cout<<ans;

}