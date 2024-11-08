#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int indeg[32001];
vector<int> adj[32001];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  vector<int> result;
  queue<int> q;
  int n,m;
  cin>>n>>m;
  int u,v;
  for(int i=0;i<m;i++)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    indeg[v]++;
  }
  for(int i=1;i<=n;i++)
  {
    if(indeg[i]==0)
      q.push(i);
  }
  while(!q.empty())
  {
    int cur=q.front();
    //cout<<cur<<' '<<'\n';
    q.pop();
    result.push_back(cur);
    for(auto nxt:adj[cur])
    {
      indeg[nxt]--;
      if(indeg[nxt]==0)
        q.push(nxt);
    }
  }
   for(auto temp: result)
       cout<<temp<<' ';



}