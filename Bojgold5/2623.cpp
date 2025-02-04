#include<bits/stdc++.h>

using namespace std;

int p[1001];
vector<int> adj[1001];
int degree[1001];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    p[i]=i;
  cout<<'\n';
  int v,t,s;
  for(int i=1;i<=m;i++)
  {
    cin>>t;
    int prev=0;
    int v;
    for(int j=0;j<t;j++)
    {
      cin>>v;
      adj[prev].push_back(v);
      prev=v;
    }
  }
  bool cycle=false;
  bool flag=true;
  int u=1;

  for(int i=1;i<=n;i++)
  {
    for(auto v:adj[i])
      degree[v]++;
  }
  queue<int> q;
  vector<int> toporder;
  for(int i=1;i<=n;i++)
    if(degree[i]==0)q.push(i);
  while(!q.empty())
  {
    int cur=q.front();
    toporder.push_back(cur);
    q.pop();
    for(auto next:adj[cur])
    {
      degree[next]--;
      if(degree[next]==0)
        q.push(next);
    }
  }
  if(toporder.size()<n)
  {
    cout<<0;
    return 0;
  }
  for(auto temp: toporder)
    cout<<temp<<'\n';

}