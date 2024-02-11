#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>

using namespace std;
int parent[100001];

int find(int u) //루트찾기
{
  if(parent[u]==u)
    return u;
  return parent[u]=find(parent[u]);
}
void merge(int u,int v) //루트 합치기 
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
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    parent[i]=i;
  tuple<int,int,int> edge[m+1]; //cost,a,b
  int a,b,c;
  for(int i=0;i<m;i++)
  {
    cin>>a>>b>>c;
    edge[i]={c,a,b};
  }
  sort(edge,edge+m);
  int mstn=0;
  int mtotal=0;
  int max=0;
  for(int i=0;i<m;i++)
  {
    int cost,u,v;
    tie(cost,u,v)=edge[i];
    if(find(u)==find(v))continue;
    merge(u,v);
    if(cost>=max)
      max=cost;
    mtotal+=cost;
    mstn++;
    if(mstn==n-1)
      break;
  }
  cout<<mtotal-max;
  

}