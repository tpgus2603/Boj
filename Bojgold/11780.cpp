#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100000000
int dp[101][101];
int nxt[101][101];
vector<int> cnt[101][101];

int main()
{

  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i <= 100; i++)
  {
    for (int j = 0; j <= 100; j++)
    {
      if (i == j)
        dp[i][j] = 0;
      else
        dp[i][j] = MAX;
    }
  }
  int n, m;
  cin >> n >> m;
  int a, b, c;
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b >> c;
    if (dp[a][b] > c)
    {
      dp[a][b] = c;
      nxt[a][b] = b;
    }
  }
  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        int minv = min(dp[i][j], dp[i][k] + dp[k][j]);
        if (minv != dp[i][j])    // k를 거쳐서 업데이트 된거라면
          nxt[i][j] = nxt[i][k]; // i->j로 갈때 i다음경로는 k를 거치는 경로로 수정
        dp[i][j] = minv;
      }
    }
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (dp[i][j] == MAX)
        cout << '0' << ' ';
      else
        cout << dp[i][j] << ' ';
    }
    cout << '\n';
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (dp[i][j] == MAX || dp[i][j] == 0)
      {
        cout << '0' << '\n';
        continue;
      }
      int temp = i;
      vector<int> path;
      while (temp != j)
      {
        path.push_back(temp);
        temp = nxt[temp][j];
      }
      path.push_back(j);//마지막 경로 추가 
      cout<<path.size()<<' ';
      for(auto k:path)
       cout<<k<<' ';
      cout<<'\n';
    }
  }
}
