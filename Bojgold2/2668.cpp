#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

bool vis[101];
bool vis2[101];
int arr[101];
int n;
vector<int> temp;
bool func(int first,int nxt)
{
  if(nxt==first)
  {
    return true;
  }
  else if(vis[nxt]||vis2[nxt]||nxt>n)
    return false;
  vis2[nxt]=true;
  temp.push_back(nxt);
  return func(first,arr[nxt]);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> ans;
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    fill(vis2,vis2+n+1,false);
    vis2[i]=true;
    temp.clear();
    temp.push_back(i);
    bool flag=func(i,arr[i]);
    if(flag)
    {
      for(auto t:temp)
      {
        vis[t]=true;
        ans.push_back(t);
      }
    }
  }
  sort(ans.begin(),ans.end());
  cout<<ans.size()<<'\n';
  for(auto cur:ans )
  {
    cout<<cur<<'\n';
  }

}