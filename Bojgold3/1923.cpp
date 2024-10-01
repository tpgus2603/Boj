#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
int p[1001];

int find(int u)
{
  if(p[u]==u)
    return u;
  return p[u]=find(p[u]);

}
void merge(int u,int v)
{
  u=find(u);
  v=find(v);
  if(u==v)
    return;
  else
    p[u]=v;
}

int main()
{
  ios::sync_with_stdio(0);  cin.tie(0);
  int n,m;
  cin>>n>>m;
  int u,v,c;
  vector<tuple<int,int,int>> edge;
  for(int i=0;i<m;i++)
  {
    cin>>u>>v>>c;
    edge.push_back({c,u,v});
  }
  sort(edge.begin(),edge.end());
  for(int i=1;i<=n;i++)
    p[i]=i;
  int mtotal=0;
  int cnt=0;
  for(int i=0;i<m;i++)
  {
    tie(c,u,v)=edge[i];
    if(find(u)==find(v))continue;
    merge(u,v);
    mtotal+=c;
    cnt++;
    if(cnt==n-1)
      break;
  }
  cout<<mtotal;

}