#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int vis[10];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  vector<int> arr;
  int temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    arr.push_back(temp);
  }
  int left=0;
  int kind=0;  
  int maxn=0;
  int cnt=0;
  for(int cur=0;cur<n;cur++)
  {
    if(vis[arr[cur]]==0)
    {
      kind++;
    }
    vis[arr[cur]]++;
    cnt++;
    cout<<kind<<' '<<cnt<<'\n';
    if(kind>2)
    {
      cnt--;
      vis[arr[left]]--;
      if(vis[arr[left]]==0)kind--;
      left++;
    }
    maxn=max(maxn,cnt);

  }
  cout<<maxn;
}