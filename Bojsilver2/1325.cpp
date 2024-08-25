#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>

using namespace std;
int result[10001];
vector<int> adj[10001];
int main()
{
  int maxn=0;
  vector<int> maxarr;
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  int u,v;
  for(int i=0;i<m;i++)
  {
    cin>>u>>v;
    adj[v].push_back(u); // v가 u의 신뢰를 받음 
  }
  for(int i=1;i<=n;i++)
  {
    bool vis[10001];
    fill(vis,vis+n+1,false);
    queue<int> q;
    q.push(i);
    vis[i]=true;
    int cnt=0;
    while(!q.empty())
    { 
      int cur=q.front();
      q.pop();
      cnt++;
      for(auto next:adj[cur])
      {
        if(vis[next])continue;
        vis[next]=true;
        q.push(next);
      }
    }
    result[i]=cnt;
    maxn=max(maxn,cnt);
  }
  
  for(int i=1;i<=n;i++)
  {
    if(result[i]==maxn)
      cout<<i<<' ';
  }

}