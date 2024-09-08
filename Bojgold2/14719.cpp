#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int h,w;
  cin>>h>>w;
  vector<int> arr;
  int temp;
  for(int i=0;i<w;i++)
  { 
    cin>>temp;
    arr.push_back(temp);
  }
  int left=0,right=0;
  int len=arr.size();
  int cnt=0;
  for(int i=1;i<len-1;i++)
  {
    int left=0,right=0;
    for(int j=0;j<i;j++)
      left=max(left,arr[j]);
    for(int j=len-1;j>i;j--)
      right=max(right,arr[j]);
    cnt+=max(0,min(left,right)-arr[i]);
  }
  cout<<cnt;

}