#include<iostream>
#include<algorithm>
#include<tuple>
#include<vector>
#include<queue>
#include<utility>
#define V second 
#define C first

using namespace std;

int d[50001];
vector<pair<int,int>> adj[50001];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  int u,v,c;
  for(int i=0;i<m;i++)
  {
    cin>>u>>v>>c;
    adj[u].push_back({c,v});
    adj[v].push_back({c,u});
  }
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  fill(d,d+n+1,100000000);
  d[1]=0;
  pq.push({d[1],1});
  while(!pq.empty())
  { 
    auto cur=pq.top();
    pq.pop();
    if(d[cur.V]!=cur.C)continue;
    for(auto nxt:adj[cur.V])
    {
      if(d[nxt.V]>d[cur.V]+nxt.C)
      {
        d[nxt.V]=d[cur.V]+nxt.C;
        pq.push({d[nxt.V],nxt.V});
      }
    }
  }
  cout<<d[n];
}