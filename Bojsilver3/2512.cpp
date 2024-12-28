#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  vector<int> arr;
  int temp;
  int sum=0;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    arr.push_back(temp);
  }
  int m;
  cin>>m;
  sort(arr.begin(),arr.end());
  int cur=m;
  int upbound=0;
  for(int i=0;i<n;i++)
  {
    if(cur/(n-i)>arr[i])
    {
      cur-=arr[i];
    }
    else 
    {
      upbound=(cur)/(n-i);
      break;
    }
  }
  upbound==0 ? cout<<arr[n-1] : cout<<upbound;

}