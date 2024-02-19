#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>

#define MAX 0xffffffff
#define ll long long
#define C first
#define V second
using namespace std;

ll d[1001];
vector<pair<int,int>> adj[1001];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  int a,b,c;
  for(int i=0;i<m;i++)
  {
    cin>>a>>b>>c;
    adj[a].push_back({c,b});
  }
  int st,ed;
  cin>>st>>ed;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
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
  cout<<d[ed];


}