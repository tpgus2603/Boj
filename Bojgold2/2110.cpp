#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,c;
vector<int> arr;

bool solve(int dis)
{
  int prev=0;
  int cnt=1;
  for(int i=1;i<n;i++)
  {
    if(arr[i]-arr[prev]>=dis)
    {
      cnt++;
      prev=i;
    }
  }
    return cnt>=c;
}
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n>>c;
  int temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    arr.push_back(temp);
  }
  sort(arr.begin(),arr.end());
  int st=1;
  int en=arr[n-1]-arr[0];
  while(st<en)
  {
    int mid=(st+en+1)/2;
    if(solve(mid))
    {
      st=mid;
    }
    else
    {
      en=mid-1;
    }
  }
  cout<<st;

  


}