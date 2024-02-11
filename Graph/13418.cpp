#include<iostream>
#include<algorithm>
#include<tuple>
#include<vector>
#include<functional>

using namespace std;
int parent[1001];

bool cmp(tuple<int,int,int> a, tuple<int,int,int> b)
{
  int a1,a2,a3;
  tie(a1,a2,a3)=a;
  int b1,b2,b3;
  tie(b1,b2,b3)=b;
  return a1>b1;
    
}
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
  int n,m;
  cin>>n>>m;
  vector<tuple<int,int,int>> edge;
  int a,b,c;
  for(int i=0;i<=m;i++)
  {
    cin>>a>>b>>c;
    edge.push_back({c,a,b});
  }
  int upcnt1=0,upcnt2=0;
  int noden1=0,noden2=0;
  for(int i=0;i<=n;i++)
    parent[i]=i;
  sort(edge.begin(),edge.end());
  for(int i=0;i<=m;i++)
  {
    tie(c,a,b)=edge[i];
    if(find(a)==find(b))continue;
    merge(a,b);
    if(c==0)
      upcnt1++;
    noden1++;
    if(noden1==n)
      break;
  }
  for(int i=0;i<=n;i++)
    parent[i]=i;
  sort(edge.begin(),edge.end(),cmp);
  for(int i=0;i<=m;i++)
  {
    tie(c,a,b)=edge[i];
    if(find(a)==find(b))continue;
    merge(a,b);
    if(c==0)
      upcnt2++;
    noden2++;
    if(noden2==n)
      break;
  }
    cout<<upcnt1*upcnt1-upcnt2*upcnt2;
  


}