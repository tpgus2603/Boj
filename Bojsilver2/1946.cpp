#include<algorithm>
#include<iostream>
#include<utility>
#include<vector>

#define X first 
#define Y second 
using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<pair<int,int>> arr;
    int a,b;
    for(int i=0;i<n;i++)
    {
      cin>>a>>b;
      arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end());
    int cnt=1;
    int minn=arr[0].Y;
    for(int i=1;i<n;i++)
    {
      if(arr[i].Y<minn)
      {
        cnt++;
        minn=arr[i].Y;
      }
    }
    cout<<cnt<<'\n';
  }


}