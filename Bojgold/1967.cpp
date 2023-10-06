#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include<algorithm>
#define N first
#define D second

using namespace std;

vector<pair<int,int>> adj[10001];
int vis[10001];
int dist[10001];

pair<int, int> maxdist = {0, 0};
void dfs(int cur)
{
  stack<int> s;
  s.push(cur);
  vis[cur]=1;
  while (!s.empty())
  {
    cur=s.top();
    s.pop();
    for (auto nxt : adj[cur])
    {
      if (!vis[nxt.N])
      {
        dist[nxt.N] = dist[cur] + nxt.D;
        if (dist[nxt.N] > maxdist.D)
        {
          maxdist.D = dist[nxt.N];
          maxdist.N = nxt.N;
        }
        s.push(nxt.N);
        vis[nxt.N]=1;
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin >> n;
  int n1, n2, dst;
  for (int i = 0; i < n - 1; i++)
  {
    cin >> n1 >> n2 >> dst;
    adj[n1].push_back({n2,dst});
    adj[n2].push_back({n1,dst});
    
  }
  dfs(1);
  fill(vis,vis+10001,0);
  fill(dist,dist+10001,0);
  maxdist.D=0;
  dfs(maxdist.N);
  cout<<maxdist.D;
}