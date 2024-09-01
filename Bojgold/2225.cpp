#include<iostream>
#include<algorithm>

using namespace std;
#define MOD 1000000000
#define ll long long
ll dp[201][201]; //dp[i][j] i를 j개의 수로 만드는 경우의수 

int main()
{

  ios::sync_with_stdio(0);cin.tie(0);
  int n,k;
  cin>>n>>k;

  for(int i=0;i<=n;i++)
    dp[i][1]=1;
  for(int i=0;i<=k;i++)
    dp[0][i]=1;
  for(int i=1;i<=n;i++)
  {
    for(int j=2;j<=k;j++) //합이 3이되게
    {
      dp[i][j]=dp[i][j-1]+dp[i-1][j];
      dp[i][j]%=MOD;
    }
  }
  cout<<dp[n][k];

}