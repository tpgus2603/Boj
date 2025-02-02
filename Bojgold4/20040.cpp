#include<bits/stdc++.h>

using namespace std;

int parent[500000];
int height[500000];
#define X first 
#define Y second 
int find(int u)
{
  if(parent[u]==u)
    return u;
  return parent[u]=find(parent[u]);
}
void merge(int u,int v)
{
  u=find(u);
  v=find(v);
  if(u==v)return;
  parent[u]=v;
}

  
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  vector<pair<int,int>>edge(m);
  for(int i=0;i<n;i++)
    parent[i]=i;
  int u,v;
  for(int i=0;i<m;i++)
  {
    cin>>edge[i].X>>edge[i].Y;
  }

  bool cycle=false;

  for(int i=0;i<m;i++)
  {
    u=edge[i].X;
    v=edge[i].Y;
    if(find(u)==find(v))
    {
      cout<<i+1;
      cycle=true;
      break;
    }
    merge(u,v);
  }
  if(!cycle)cout<<0;
}