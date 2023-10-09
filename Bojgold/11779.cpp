#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<utility>

#define D first
#define V second
#define I 1e9
using namespace std;

int v,e;
vector<pair<int,int>> adj[1001];

int d[1001];
int pre[1001];

void dkstra(int st)
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
      if (d[nxt.V] <=d[cur.V] + nxt.D) // 정점+간선이 최소값이 아닌경우(부등호 포함 안하면 메모리 낭비)
        continue;
      d[nxt.V] = d[cur.V] + nxt.D; // 최소값 갱신
      pre[nxt.V]=cur.V;
      pq.push({d[nxt.V], nxt.V});   // 힙에넣기
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>v>>e;
  while(e--)
  {
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back({w,v});
  }
  int st,ed;
  cin>>st>>ed;
  dkstra(st);
  cout<<d[ed]<<'\n';
  vector<int> path;
  int temp=ed;
  while(temp!=st)
  {
    path.push_back(temp);
    temp=pre[temp];
  }
  path.push_back(st);
  int idx=path.size();
  cout<<idx<<'\n';
  for(int i=idx-1;i>=0;i--)
    cout<<path[i]<<" ";


}