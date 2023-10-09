#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<utility>

#define D first
#define V second
#define I 1e9
using namespace std;

int v,e,st;
vector<pair<int,int>> adj[20001];

int d[20001];

void dkstra()
{
  fill(d, d + v + 1, I);
  // 거리와 이웃정점 정보를 담는 힙
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  d[st] = 0;
  pq.push({d[st], st});
  while (!pq.empty())
  {
    auto cur = pq.top();
    pq.pop();
    if (d[cur.V] != cur.D) // 테이블의 값과 힙속에 저장된 거리가 다르면
      continue;
    for (auto nxt : adj[cur.V])
    {
      if (d[nxt.V] <= d[cur.V] + nxt.D) // 정점+간선이 최소값이 아닌경우
        continue;
      d[nxt.V] = d[cur.V] + nxt.D; // 최소값 갱신
      pq.push({d[nxt.V], nxt.V});   // 힙에넣기
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>v>>e>>st;
  while(e--)
  {
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back({w,v});
  }
  dkstra();
  for(int i=1;i<=v;i++)
  {
    if(d[i]==I)
      cout<<"INF"<<'\n';
    else
      cout<<d[i]<<'\n';
  }



}