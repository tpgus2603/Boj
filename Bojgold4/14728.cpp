#include<bits/stdc++.h>

using namespace std;
int dp[10001];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,t;
  cin>>n>>t;
  for(int i=0;i<n;i++)
  {
    int k,s;
    cin>>k>>s; //k:예상 공부시간 s:배점
    for(int j=t-k;j>=0;j--)
    {
      if(j!=0&&dp[j]==0)continue;
      dp[j+k]=max(dp[j]+s,dp[j+k]);
    }
  }
  cout<<*max_element(dp,dp+t+1);
}
