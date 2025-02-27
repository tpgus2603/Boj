#include<bits/stdc++.h>

#define V first 
#define C second
#define INF 2e9
using namespace std;
vector<pair<int,int>> adj[5001]; //V=도착 노드 ,C=usado값
bool vis[5001];
int usado[5001];
int k;
int cnt;
void dfs(int cur)
{
  for(auto next:adj[cur])
  {
    if(vis[next.V])continue;
    vis[next.V]=true;
    usado[next.V]=min(usado[cur],next.C);
    if(usado[next.V]>=k)cnt++;
    dfs(next.V);
  }
}

int main()
{ 
  ios::sync_with_stdio(0);cin.tie(0);
  int N,Q;
  cin>>N>>Q;
  int p,q,r;
  for(int i=0;i<N-1;i++)
  {
    cin>>p>>q>>r;
    adj[p].push_back({q,r});
    adj[q].push_back({p,r});
  }
  //모든 점에서 dfs해서 usado갱신 

  int v;
  for(int i=0;i<Q;i++)
  {

    cin>>k>>v;
    cnt=0;
    fill(vis,vis+N+1,false);
    fill(usado,usado+N+1,-1);
    vis[v]=true; //시작점 
    usado[v]=INF;
    for(auto next:adj[v])
    {
      if(vis[next.V])continue;
      vis[next.V]=true;
      usado[next.V]=min(usado[v],next.C);
      if(usado[next.V]>=k)cnt++;
      dfs(next.V);
    }
    cout<<cnt<<'\n';
  }
}