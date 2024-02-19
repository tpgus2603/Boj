#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int dp[101][10001];
bool is_make[101][10001];

int main()
{
  int testn;

    int n,m;
    cin>>n>>m;
    int coin[n+1];
    for(int i=1;i<=n;i++)
      cin>>coin[i];
    coin[0]=-1;
    sort(coin,coin+n+1);
    for(int i=0;i<=n;i++)
      is_make[i][0]=1;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(j>=coin[i])
        {
          if(is_make[i][j-coin[i]]&&is_make[i-1][j])
            {
              dp[i][j]=min(dp[i][j-coin[i]]+1,+dp[i-1][j]);
              is_make[i][j]=1;
            }
          else if(is_make[i][j-coin[i]])
            {
              dp[i][j]=dp[i][j-coin[i]]+1;
              is_make[i][j]=1;
            }
            else
            {
              if(is_make[i-1][j])
              {
                dp[i][j]=dp[i-1][j];
                is_make[i][j]=1;
              }
            }
        }
        else
          {
            dp[i][j]=dp[i-1][j];
            if(dp[i][j])
              is_make[i][j]=1;
          }
      }
    }

    if(dp[n][m]==0)
      cout<<-1;
    else
      cout<<dp[n][m]<<'\n';
}


//풀이 2
// using namespace std;
// int n, k;
// int a[10005], d[10005];
// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> n >> k;
//   for (int i = 0; i < n; i++)
//     cin >> a[i];
//   fill(d, d + 10005, 100005);
//   d[0] = 0; // 0원: 0개
//   for (int i = 0; i < n; i++) {
//     for (int j = a[i]; j <= k; j++)
//       // 동전 하나 추가한 값과 기존 값 중 작은값
//       d[j] = min(d[j], d[j - a[i]] + 1);
//   }

//   cout << (d[k] == 100005 ? -1 : d[k]) << '\n';
// }