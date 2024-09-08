#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

bool vis[2000];

vector<int> adj[2000];

bool ok=false;
void dfs(int cur, int depth )
{
  if(depth==4)
    {
      ok=true;
      return ;
    }
  for(auto nxt: adj[cur])
  {
    if(vis[nxt])continue;
    vis[nxt]=true;
    dfs(nxt,depth+1);
  }

}
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  int u,v;
  for(int i=0;i<m;i++)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=0;i<n;i++)
  {
    fill(vis,vis+n,false);
    //i에서 출발 
    vis[i]=true;
    for(auto cur: adj[i])
    {
      if(vis[cur])continue;
      vis[cur]=true;
      dfs(cur,1);
    }
    if(ok==true)
      break;
  }
  if(ok==true)
  {
    cout<<1;
  }
  else
    cout<<0;

}