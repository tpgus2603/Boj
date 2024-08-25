#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> arr;
int n,m;

bool solve(int n)
{
  int len=arr.size();
  bool flag=true;
  int cnt=1;
  int sum=0;
  for(int i=0;i<len;i++)
  {
    sum+=arr[i];
    if(sum>n)
    {
      sum=arr[i];
      cnt++;
    }
    else if(sum==n&&i!=len-1)
    {
      cnt++;
      sum=0;
    }
    if(cnt>m)return false;
  }
  return flag;
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  int sum=0;
  int temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    sum+=temp;
    arr.push_back(temp);
  }
  int st,mid,ed;
  st=*min_element(arr.begin(),arr.end());
  ed=sum;
  while(st<ed)
  {
    mid=(st+ed)/2;
    //cout<<st<<' '<<mid<<' '<<ed<<'\n';
    if(solve(mid))ed=mid;
    else st=mid+1;
  }
  // int ans=0;
  //  while(st < ed){
  //   mid = (st+ed+1)/2;
  //   if(solve(mid)) 
  //   {
  //     st = mid;
  //     ans=mid;
  //   }
  //   else ed = mid-1;
  // }
  // cout<<ans;
  cout<<ed;





}