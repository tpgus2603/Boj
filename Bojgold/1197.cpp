#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <utility>
using namespace std;

#define D first
#define N second
vector<int> parent(10001);
vector<int> ranks(10001, 1);
int v, e;
tuple<int, int, int> edge[100001];
vector<pair<int, int>> adj[100001]; // 간선에 대한 adj 거리,정점번호

int find(int u)
{
  if (u == parent[u])
    return u;
  return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
  u = find(u);
  v = find(v);
  if (u == v)
    return;
  if (ranks[u] > ranks[v])
    swap(u, v);
  // 이제 v의 랭크가 u의 랭크보다 낮지 않으므로 u를 v의 자식으로 보낸다
  parent[u] = v;
  if (ranks[u] == ranks[v])
    ranks[v]++;
}
int kruscal()
{
  sort(edge, edge + e);
  int mstn = 0;
  int mtotal = 0;
  for (int i = 1; i <= 10000; i++)
    parent[i] = i;
  for (int i = 0; i < e; i++)
  {
    int a, b, dst;
    tie(dst, a, b) = edge[i];
    if (find(a) == find(b))
      continue;    // 같은 그룹이면 스킵
    mtotal += dst; // 다른 그룹이면 추가
    mstn++;
    merge(a, b);
    if (mstn == v - 1)
      break;
  }
  return mtotal;
}

int prim()
{
  bool closed[100001];
  int cnt = 0; // 선택된 간선 수
  // 거리,정점1,정점2(간선 거리와 연결된 정점 두개까지 포함한 정보 ) 오름차순
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
  closed[1] = 1;          // 시작점 닫기
  for (auto nxt : adj[1]) // 1과 연결된 노드들 추가
    pq.push({nxt.D, 1, nxt.N});
  int mtotal=0;
  while (cnt < v - 1)
  {
    int dst, a, b;
    tie(dst, a, b) = pq.top();
    pq.pop();
    if (closed[b])
      continue;
    closed[b] = 1;
    cnt++;
    mtotal+=dst;
    for (auto nxt : adj[b]) // mst에 추가한 노드와 연결된 간선 체크
    {
      if (!closed[nxt.N]) // mst에 없는 노드면
        pq.push({nxt.D, b, nxt.N});
    }
  }
  return mtotal; 
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> v >> e;//노드의 개수edge의 개수
  for (int i = 0; i < e; i++)
  {
    int a, b, dst;
    cin >> a >> b >> dst;
    edge[i] = {dst, a, b};
    adj[a].push_back({dst,b});
    adj[b].push_back({dst,a});
  }
  int mtotal=kruscal();
  int mtotal2=prim();
  cout << mtotal2;
}