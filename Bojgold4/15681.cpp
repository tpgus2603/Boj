#include<bits/stdc++.h>

using namespace std;

vector<int> edge[100001]; //u->v;
int parent[100001];
vector<int> child[100001];
int subsize[100001];
void maketree(int cur,int par)
{
  for(auto nxt: edge[cur])
  {
    if(nxt==par)continue;
    child[cur].push_back(nxt);
    parent[nxt]=cur;
    maketree(nxt,cur);
  }
}
void func(int cur) //서브트리 개수구하는 함수 
{
  subsize[cur]=1;
  for(auto nxt : child[cur])
  {
    func(nxt);
    subsize[cur]+=subsize[nxt];
  }
}
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int  n,r,q;
  cin>>n>>r>>q;
  int u,v;
  for(int i=0;i<n-1;i++)
  {
    cin>>u>>v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  for(int i=1;i<=n;i++)
    parent[i]=r;
  maketree(r,r);
  func(r);
  vector<int> root(q,0);
  for(int i=0;i<q;i++)
  {
    cin>>u;
    cout<<subsize[u]<<'\n';
  }

}