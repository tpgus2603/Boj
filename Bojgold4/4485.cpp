#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;
#define D first  
#define V second
#define I 10000000
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int t=1;
  while(1)
  {
    int n;
    cin>>n;
    if(n==0)break;
    int arr[n][n];
    int dp[n*n];
    vector<pair<int,int>> adj[n*n];
    int temp;
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
         cin>>arr[i][j];
    fill(dp,dp+n*n,I);
    // edge계산후 인접리스트 만들기 
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        int cur=i*n+j;
        //좌
        if(j!=0)
        {
          adj[cur].push_back({arr[i][j-1],cur-1});
        }
        //우
        if(j!=n-1)
        {
          adj[cur].push_back({arr[i][j+1],cur+1});
        }
        //위
        if(i!=0)
        {
          adj[cur].push_back({arr[i-1][j],cur-n});
        } 
        //아래
        if(i!=n-1)
        {
          adj[cur].push_back({arr[i+1][j],cur+n});
        } 
      }
    }
    dp[0]=arr[0][0];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({dp[0],0});
    while(!pq.empty())
    {
      auto cur=pq.top();
      pq.pop();
      if(cur.D!=dp[cur.V])continue;
      for(auto next:adj[cur.V])
      {
        if(dp[next.V]>dp[cur.V]+next.D)
        {
          dp[next.V]=dp[cur.V]+next.D;
          pq.push({dp[next.V],next.V});          
        }
      }
    }

    cout<<"Problem "<<t++<<": "<<dp[n*n-1]<<'\n';
  }


}



// #include <bits/stdc++.h>
// using namespace std;

// const int INF = 987654321;
// const int dy[] = {-1, 0, 1, 0};
// const int dx[] = {0, 1, 0, -1};
// int n, t, a[130][130], dist[130][130];

// void dijkstra() {
//   priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
//                  greater<pair<int, pair<int, int>>>>
//       pq;

//   dist[0][0] = a[0][0];
//   pq.push({a[0][0], {0, 0}});

//   while (pq.size()) {
//     int here_cost = pq.top().first;

//     int y, x;
//     tie(y, x) = pq.top().second;

//     pq.pop();

//     // printf("%d : %d\n", y, x);

//     if (here_cost != dist[y][x]) continue;

//     for (int i = 0; i < 4; i++) {
//       int ny = y + dy[i];
//       int nx = x + dx[i];

//       if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

//       int new_cost = here_cost + a[ny][nx];

//       if (dist[ny][nx] > new_cost) {
//         dist[ny][nx] = new_cost;
//         pq.push({new_cost, {ny, nx}});
//       }
//     }
//   }
// }

// int main() {
//   while (true) {
//     cin >> n;
//     if (n == 0) break;
//     t++;
//     fill(&dist[0][0], &dist[0][0] + 130 * 130, INF);
//     fill(&a[0][0], &a[0][0] + 130 * 130, -1);

//     for (int i = 0; i < n; i++) {
//       for (int j = 0; j < n; j++) {
//         cin >> a[i][j];
//       }
//     }

//     dijkstra();
//     printf("Problem %d: %d\n", t, dist[n - 1][n - 1]);
//   }

//   return 0;
// }

// // 2차원 가중치가 다른 최단거리 - 다익스트라
// // y, x의 좌표를 2차원으로 생성할 수도 있지만, y*1000 + x 로 하나의 정수에 담을 수 있다.
// // 사용할때는 a / 1000, a % 1000 으로 꺼내서 사용가능