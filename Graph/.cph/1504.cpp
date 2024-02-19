#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>

#define MAX 100000000
#define C first
#define V second

using namespace std;

int d[801];
int n,e;
vector<pair<int,int>> adj[801];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
int dkj(int st,int ed)
{
  fill(d,d+n+1,MAX);
  d[st]=0;
  pq.push({d[st],st});
  while(!pq.empty())
  {
    auto cur=pq.top();
    pq.pop();
    if(d[cur.V]!=cur.C)
      continue;
    for(auto nxt:adj[cur.V])
    {
      if(d[nxt.V]>d[cur.V]+nxt.C)
      {
        d[nxt.V]=d[cur.V]+nxt.C;
        pq.push({d[nxt.V],nxt.V});
    }
    }
  }
  return d[ed];
}
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n>>e;
  int a,b,c;
  for(int i=0;i<e;i++)
  {
    cin>>a>>b>>c;
    adj[a].push_back({c,b});
    adj[b].push_back({c,a});
  }
  int u,v;
  cin>>u>>v;
  int ans= min(dkj(1,u)+dkj(u,v)+dkj(v,n),dkj(1,v)+dkj(v,u)+dkj(u,n));
  if(ans>=MAX)
    cout<<-1;
  else
    cout<<ans;
}