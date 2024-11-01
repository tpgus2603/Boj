#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<utility>

#define V first 
#define D second
using namespace std;

vector<pair<int,int>> adj[1001];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m,u,v,d;
  cin>>n>>m;
  for(int i=0;i<n-1;i++)
  {
    cin>>u>>v>>d;
    adj[u].push_back({v,d});
    adj[v].push_back({u,d});
  }
  for(int i=0;i<m;i++)
  {
    int st,ed;
    cin>>st>>ed;
    queue<int> q;
    q.push(st);
    int dis[1001];
    fill(dis,dis+n+1,-1);
    dis[st]=0;
    while(!q.empty())
    {
      int cur=q.front();
      q.pop();
      if(cur==ed)break;
      for(auto nxt:adj[cur])
      {
        if(dis[nxt.V]!=-1)continue;
        dis[nxt.V]=dis[cur]+nxt.D;
        q.push(nxt.V);
      }
    }
    cout<<dis[ed]<<'\n';
  }
}
