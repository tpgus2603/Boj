#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int vis[1001];
vector<int> adj[1001];

void dfs(int cur)
{
  for(auto nxt:adj[cur])
  {
    if(!vis[nxt])
    {
      vis[nxt]=1;
      dfs(nxt);
    }
  }

}


int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  int a,b;
  int cnt=0;
  for(int i=0;i<m;i++)
  {
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i=1;i<=n;i++)
  {
    if(!vis[i])
    { 
      vis[i]=1;
      cnt++;
      for(auto nxt: adj[i])
      { 
        if(!vis[nxt])
        {
          vis[nxt]=1;
          dfs(nxt);
        }
      }
    }
  }
  cout<<cnt;





}