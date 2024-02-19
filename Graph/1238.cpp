#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#define C first
#define V second
#define MAX 10000000
using namespace std;
int d1[1001];
int d2[1001];
vector<pair<int,int>> adj[1001];
int n,m,ed;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>ed;
  int a,b,c;
  for(int i=1;i<=m;i++)
  {
    cin>>a>>b>>c;
    adj[a].push_back({c,b});
  }
  fill(d1,d1+n+1,MAX);
  d1[ed]=0;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  pq.push({d1[ed],ed});
  while(!pq.empty())
  {
    auto cur=pq.top();
    pq.pop();
    if(d1[cur.V]!=cur.C)continue;
    for(auto nxt: adj[cur.V])
    {
      if(d1[nxt.V]>d1[cur.V]+nxt.C)
      {
        d1[nxt.V]=d1[cur.V]+nxt.C;
        pq.push({d1[nxt.V],nxt.V});

      }
    }
  }
  vector<int> dst;
  for(int st=1;st<=n;st++)
  {
    fill(d2,d2+n+1,MAX);
    d2[st]=0;
    pq.push({d2[st],st});
    while(!pq.empty())
    {
      auto cur=pq.top();
      pq.pop();
      if(d2[cur.V]!=cur.C)continue;
      for(auto nxt:adj[cur.V])
      {
        if(d2[nxt.V]>d2[cur.V]+nxt.C)
        {
          d2[nxt.V]=d2[cur.V]+nxt.C;
          pq.push({d2[nxt.V],nxt.V});
        }
      }
    }
    dst.push_back(d1[st]+d2[ed]);
  }
  sort(dst.begin(),dst.end());
  cout<<dst[dst.size()-1];
}