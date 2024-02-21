#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>

#define MAX 0x3f3f3f3f3f3f3f3f
#define C first
#define V second
#define ll long long 
using namespace std;

vector<pair<int,int>> adj[10001];
ll dp[21][10001];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m,k;
  cin>>n>>m>>k;
  for(int i=0;i<m;i++)
  {
    int a,b,c;
    cin>>a>>b>>c;
    adj[a].push_back({c,b});
    adj[b].push_back({c,a});
  }
  for (int i = 0; i <= k; i++)
  {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    fill(dp[i], dp[i] + n + 1, MAX);
    dp[i][1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
      auto cur = pq.top();
      pq.pop();
      if (dp[i][cur.V] != cur.C)
        continue;
      for (auto nxt : adj[cur.V])
      {
        if (i > 0)
        {
          ll cost = min(dp[i][cur.V] + nxt.C, dp[i - 1][cur.V]);
          if (dp[i][nxt.V] > cost)
          {
            dp[i][nxt.V] = cost;
            pq.push({cost, nxt.V});
          }
        }
        else
        {
          ll cost = dp[i][cur.V] + nxt.C;
          if (dp[i][nxt.V] > cost)
          {
            dp[i][nxt.V] = cost;
            pq.push({cost, nxt.V});
          }
        }
      }
    }
  }

  cout<< dp[k][n];
}


