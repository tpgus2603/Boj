#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int dp[50001];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  // for(int i=1;i<=223;i++)
  // {
  //   dp[i*i]=1;
  // }
  int n;
  cin>>n;
  dp[1]=1;
  for(int i=2;i<=n;i++)
  {
    int mi=10000;
    for(int j=1;j*j<=i;j++)
    {
      if(mi>dp[i-j*j])mi=dp[i-j*j];
    }
    dp[i]=mi+1;
  }
  cout<<dp[n];
  

}