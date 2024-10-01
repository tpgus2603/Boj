#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;
vector<int> adj[201];
bool vis[201];

void dfs(int cur)
{
  for(auto nxt:adj[cur])
  {
    if(vis[nxt])continue;
    vis[nxt]=true;
    dfs(nxt);
  }
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  int temp;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cin>>temp;
      if(temp==0)continue;
      adj[i].push_back(j);
      adj[j].push_back(i);
    }
  }
  vector<int> arr; //여행경로 
  for(int i=0;i<m;i++)
  {
    cin>>temp;
    arr.push_back(temp);
  }
  for(int i=0;i<m-1;i++)
  {
    int st=arr[i];
    fill(vis,vis+n+1,false);
    vis[st]=true;
    for(auto nxt:adj[st])
    {
      if(vis[nxt])continue;
      vis[nxt]=true;
      dfs(nxt);
    }
    if(!vis[arr[i+1]])
    {
      cout<<"NO";
      return 0;
    }
  }
  cout<<"YES";


}