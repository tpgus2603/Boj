#include <iostream>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <vector>

#define D first
#define V second

using namespace std;
int closed[301];
int n;
vector<pair<int, int>> adj[301]; // 거리,도착노드번호

int prim()
{
  int cnt = 0;
  int mtotal = 0;
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq; // 거리 시작노드 도착노드
  closed[0] = 1;
  for (auto nxt : adj[0])
    pq.push({nxt.D, 0, nxt.V});
  while (cnt < n )
  {
    int dst, a, b;
    tie(dst, a, b) = pq.top();
    pq.pop();
    if (closed[b])
      continue;
    closed[b] = 1;
    cnt++;
    mtotal += dst;  
    for (auto nxt : adj[b])
    {
      if (!closed[nxt.V])
        pq.push({nxt.D, b, nxt.V});
    }
  }

  return mtotal;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int temp;
  for (int i = 1; i <= n; i++)
  {
    cin >> temp;
    adj[0].push_back({temp,i});
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      int cost;
      cin >> cost;
      if (cost != 0)
      {
        adj[i].push_back({cost, j});
      }
    }
  }
  cout<<prim();
}