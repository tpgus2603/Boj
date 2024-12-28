#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#define D first 
#define V second
#define I 0x3f3f3f3f
using namespace std;

vector<pair<int,int>> adj[10001];
int dp[10001];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,d;
  cin>>n>>d;
  for(int i=0;i<d;i++)
    adj[i].push_back({1,i+1});
  for(int i=0;i<n;i++)
  {
    int u,v,d;
    cin>>u>>v>>d;
    adj[u].push_back({d,v});
  }
  fill(dp,dp+d+1,I);
  dp[0]=0;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  pq.push({dp[0],0});
  while(!pq.empty())
  {
    auto cur =pq.top();
    pq.pop();
    if(dp[cur.V]!=cur.D)continue;
    for(auto nxt:adj[cur.V])
    {
      if(dp[nxt.V]>dp[cur.V]+nxt.D&&cur.V<nxt.V)
      {
        dp[nxt.V]=dp[cur.V]+nxt.D;
        pq.push({dp[nxt.V],nxt.V});
      }
    }
  }
  cout<<dp[d];

}
// int main()
// {
//     int n,d,r=0,t=0; cin >> n >> d;
//     int D[10101];
    
//     D[0] = 0;
//     for(int i=0; i<n; i++){
//         int p,q,r;
//         cin >> p >> q >> r;
//         v[q].push_back({r,p});
//     }
//     for(int j=1; j<=d; j++){
//         D[j] = D[j-1] + 1;
//         for(int i=0; i<v[j].size(); i++){
//             D[j] = min(D[j], D[v[j][i].second] + v[j][i].first);
//         }
//     }


//     cout << D[d];
// }