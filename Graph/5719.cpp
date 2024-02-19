#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<tuple>

#define MAX 1000000000
#define C first
#define V second
using namespace std;

int d1[500];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  while(1)
  {
    vector<tuple<int,int,int>> adj[500];
    vector<tuple<int,int,int>> b_adj[500];
    bool s_path[10000];
    int n,m;
    cin>>n>>m;
    if(n==0&&m==0)
      break;
    int s,d;
    cin>>s>>d;
    for(int i=0;i<m;i++)
    {
      int u,v,p;
      cin>>u>>v>>p;
      adj[u].push_back({p,v,i});
      b_adj[v].push_back({p,u,i});
    }
    fill(d1,d1+n,MAX);
    fill(s_path,s_path+m,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    d1[s]=0;
    pq.push({d1[s],s});
    while(!pq.empty())  //테이블 만들기 
    {
      auto cur=pq.top();
      pq.pop();
      if(d1[cur.V]!=cur.C)continue;
      for(auto [nxt_c,nxt_v,edge]:adj[cur.V])
      {
        if(d1[nxt_v]>d1[cur.V]+nxt_c)
          {
            d1[nxt_v]=d1[cur.V]+nxt_c;
            pq.push({d1[nxt_v],nxt_v});
          }
      }
    }
    queue<int>q;
    q.push(d);   // 모든 최적 경로의 edge 표시하기
    while(!q.empty())
    {
      auto cur=q.front();
      q.pop();
      for(auto [pre_c,pre_v,edge]:b_adj[cur])
      { 
        if(s_path[edge])continue;
        int cost= d1[cur]-pre_c;
        if(cost!=d1[pre_v])continue;
        q.push(pre_v);
        s_path[edge]=true;
      }
    }
    fill(d1,d1+n,MAX);  //최적 경로 아닌 경로에 대해 다익스트라 다시하기 
    d1[s]=0;
    pq.push({d1[s],s});
    while(!pq.empty())
    {
      auto cur=pq.top();
      pq.pop();
      if(d1[cur.V]!=cur.C)continue;
      for(auto [nxt_c,nxt_v,edge]:adj[cur.V])
      {
        if(s_path[edge]) continue;
        if(d1[nxt_v]>d1[cur.V]+nxt_c)
          {
            d1[nxt_v]=d1[cur.V]+nxt_c;
            pq.push({d1[nxt_v],nxt_v});
          }
      }
    }
    if(d1[d]>=MAX)
      cout<<-1<<'\n';
    else
      cout<<d1[d]<<'\n';

  }


}