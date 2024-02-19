#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

#define MAX 0x3f3f3f3f3f3f3f3f
#define ll long long
#define C first
#define V second

using namespace std;
ll d[100001];
vector<pair<int,int>> adj[100001];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);

  int n,m,k;
  cin>>n>>m>>k;
  int u,v,c;
  for(int i=0;i<m;i++)
  {
    cin>>u>>v>>c;
    adj[v].push_back({c,u});
 }
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
  int temp;
  fill(d+1,d+n+1,MAX);
  for(int i=0;i<k;i++)
  {
    cin>>temp;
    d[temp]=0;
    pq.push({0,temp});
  }
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
  ll ma=*max_element(d+1,d+n+1);
  vector<int> arr;
  for(int i=1;i<=n;i++)
  {
    if(d[i]==ma)
    { 
      arr.push_back(i);
      break;
    }
  }
    cout<<arr[0]<<'\n'<<ma;
}