#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> adj[1001];
int vis[1001];


void dfs(int cur)
{
  cout<<cur<<' ';
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
  int n,m,startn;
  cin>>n>>m>>startn;
  int a,b;
  for(int i=0;i<m;i++)
  {
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i=1;i<=n;i++)
  {
    sort(adj[i].begin(),adj[i].end());
  }
  vis[startn]=1;
  cout<<startn<<' ';
  for(auto nxt:adj[startn])
  {
    if(!vis[nxt])
    {
      vis[nxt]=1;
      dfs(nxt);
    }
  }
  cout<<'\n';
  fill(vis,vis+n+1,0);
  queue<int> bfs;
  vis[startn]=1;
  bfs.push(startn);
  while(!bfs.empty())
  {
    int cur=bfs.front();
    cout<<cur<<' ';
    bfs.pop();
    for(auto nxt: adj[cur])
    {
      if(!vis[nxt])
      {
        vis[nxt]=1;
        bfs.push(nxt);
      }
    }

  }



}