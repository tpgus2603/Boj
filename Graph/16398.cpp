#include<iostream>
#include<algorithm>
#include<tuple>
#include<vector>

#define ll long long 

using namespace std;

int parent[1001];

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
  if(u==v)
    return;
  parent[u]=v;
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  vector<tuple<int,int,int>> edge;
  int n;
  cin>>n;
  int cost,a,b;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cin>>cost;
      if(j<i)
        edge.push_back({cost,i,j});
    }
  }
  sort(edge.begin(),edge.end());
  for(int i=1;i<=n;i++)
    parent[i]=i;
  ll mtotal=0;
  ll mcnt=0;
  int e=edge.size();
  int u,v;
  for(int i=0;i<e;i++)
  {
    tie(cost,u,v)=edge[i];
    if(find(u)==find(v))continue;
    merge(u,v);
    mtotal+=cost;
    mcnt++;
    if(mcnt==n-1)
      break;
  }
    cout<<mtotal;
    
}