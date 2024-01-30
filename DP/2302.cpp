#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int dp[41][2];
int vip[41];

int n,m;
int main()
{

ios::sync_with_stdio(0);cin.tie(0);

  cin>>n>>m;
  int temp;
  for(int i=0;i<m;i++)
   {
      cin>>temp;
      vip[temp]=1;
   }
   dp[1][1]=1;
   if(!vip[2])
    dp[2][0]=1;
   dp[2][1]=1;

  for(int i=3;i<=n;i++)
  {
    if(!vip[i]&&!vip[i-1])
    {
        dp[i][1]=dp[i-1][0]+dp[i-1][1];
        dp[i][0]=dp[i-2][0]+dp[i-2][1];
    }
    else{
        dp[i][1]=dp[i-1][0]+dp[i-1][1];
    }
  }
  cout<<dp[n][0]+dp[n][1];



}