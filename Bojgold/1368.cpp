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
int parent[301];
int n;
vector<pair<int, int>> adj[301]; // 거리,도착노드번호

vector<tuple<int,int,int>> edge;
vector<int>ranks(301,1);

int find(int u)
{
  if(parent[u]==u)
    return u;
  return parent[u]=find(parent[u]);
}

void merge(int u,int v)
{
   u=find(u);
   v=find(v);
  if(u==v)
    return;
  if(ranks[u]>ranks[v])
    swap(ranks[u],ranks[v]);
  parent[u]=v;
  if(ranks[u]==ranks[v])
    ranks[v]++;
}
int kruscal()
{
  int cnt=0;
  int mtotal=0;
  sort(edge.begin(),edge.end());
  auto k=edge.size();
  for(int i=0;i<k;i++)
  {
   int dst,u,v;
   tie(dst,u,v)=edge[i];
   if(find(u)==find(v))continue;
   merge(u,v);
   mtotal+=dst;
   cnt++;
   if(cnt==n-1)
    break;
  }
  return mtotal;
}



// int prim()
// {
//   int cnt = 0;
//   int mtotal = 0;
//   priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq; // 거리 시작노드 도착노드
//   closed[0] = 1;
//   for (auto nxt : adj[0])
//     pq.push({nxt.D, 0, nxt.V});
//   while (cnt < n )
//   {
//     int dst, a, b;
//     tie(dst, a, b) = pq.top();
//     pq.pop();
//     if (closed[b])
//       continue;
//     closed[b] = 1;
//     cnt++;
//     mtotal += dst;  
//     for (auto nxt : adj[b])
//     {
//       if (!closed[nxt.V])
//         pq.push({nxt.D, b, nxt.V});
//     }
//   }

//   return mtotal;
// }

// int main()
// {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> n;
//   int temp;
//   for (int i = 1; i <= n; i++)
//   {
//     cin >> temp;
//     adj[0].push_back({temp,i});
//   }
//   for (int i = 1; i <= n; i++)
//   {
//     for (int j = 1; j <= n; j++)
//     {
//       int cost;
//       cin >> cost;
//       if (cost != 0)
//       {
//         adj[i].push_back({cost, j});
//       }
//     }
//   }
//   cout<<prim();
// }



int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int temp;
  for(int i=0;i<=n;i++)
    parent[i]=i;
  for (int i = 1; i <= n; i++)
  {
    cin >> temp;
    edge.push_back({temp,0,i});
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      int cost;
      cin >> cost;
      if (cost != 0)
      {
        edge.push_back({cost,i,j});
      }
    }
  }
  cout<<kruscal();
}