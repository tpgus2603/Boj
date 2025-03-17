#include<bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  vector<int> arr;
  int n;
  cin>>n;
  int t;
  for(int i=0;i<n;i++)
  {
    cin>>t;
    arr.push_back(t);
  }
  int cnt=0;
  sort(arr.begin(),arr.end());
  for(int i=0;i<n;i++)
  { 
    int target=arr[i];
    int st=0;
    int ed=n-1;
    bool flag=false;
    if(ed==i)ed--;
    if(st==i)st++;
    while(st<ed)
    {

      int temp=arr[st]+arr[ed];
      if(temp==target){
        flag=true;
        break;
      }
      else if(temp>target)ed--;
      else st++;
      if(ed==i)ed--;
      if(st==i)st++;
    }
    if(flag)cnt++;
  }
  cout<<cnt;
}