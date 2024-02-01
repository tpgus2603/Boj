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
      // if(coin[i]==coin[i-1])
      //   continue;
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