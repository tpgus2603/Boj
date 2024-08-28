#include<iostream>
#include<algorithm>

using namespace std;
int parent[1000001];
int n,m;
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
  cin>>n>>m;
  for(int i=0;i<=n;i++)
  {
    parent[i]=i;
  }
  int t,a,b;
  for(int i=0;i<m;i++)
  {
    cin>>t>>a>>b;
    if(t==0)
    {
      merge(a,b);
    }
    else
    {
      if(find(a)==find(b))
        cout<<"YES"<<'\n';
      else
        cout<<"NO"<<'\n';
    }

  }

}