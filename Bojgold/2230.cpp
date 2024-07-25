#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  vector<ll>arr;
  int temp;
  for(int i=0;i<n;i++)
  { 
    cin>>temp;
     arr.push_back(temp);
  }
  sort(arr.begin(),arr.end());
  ll minn =2000000001;
  for(int i=0;i<n;i++)
  {
    auto it=lower_bound(arr.begin(),arr.end(),arr[i]+m);
    if(it!=arr.end())
      minn=min(minn,*it-arr[i]);
  }
  cout<<minn;
}