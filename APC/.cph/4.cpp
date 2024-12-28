#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
#define MOD 1000000007
using namespace std;
#define ll long long 
ll dp[10000001];
ll sum[10000001];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int q;
  dp[1]=5;dp[2]=20;
  sum[1]=5; sum[2]=25;
  cin>>q;
  for(int i=3;i<=10000000;i++)
  {
    dp[i]=4*(sum[i-1])%MOD;
    sum[i]=(sum[i-1]+dp[i])%MOD;
  }
  int n;
  for(int i=0;i<q;i++)
  {
    cin>>n;
    cout<<dp[n]<<'\n';
  }
}