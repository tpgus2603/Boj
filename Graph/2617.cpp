#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

vector<int> adj[100];

int h[100];
int l[100];
int vis[100];

int main()
{
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
  }
  for(int i=1;i<=n;i++)
  {
    fill(vis,vis+100,0);
    stack<int> dfs;
    dfs.push(i);
    while(!dfs.empty())
    {
      int cur=dfs.top();
      dfs.pop();
      if(vis[cur])continue;
       vis[cur]=1;
      l[i]++;
      h[cur]++;
      for(auto nxt:adj[cur])
      {
        if(vis[nxt])continue;
        dfs.push(nxt);
      }
    }
  }
  int mid=(n+1)/2+1;
  int cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(l[i]>=mid||h[i]>=mid)
      cnt++;
  }
  cout<< cnt;
}