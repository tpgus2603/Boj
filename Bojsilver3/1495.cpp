#include<iostream>
#include<algorithm>
#include<vector>
bool dp[51][1001];
int arr[51];
using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,s,m;
  cin>>n>>s>>m;
  for(int i=1;i<=n;i++)
  { 
    cin>>arr[i];
  }
  dp[0][s]=true;
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<=m;j++)
    {
      if(!dp[i-1][j])continue;
      if(j-arr[i]>=0)
        dp[i][j-arr[i]]=true;
      if(j+arr[i]<=m)
        dp[i][j+arr[i]]=true;
    }    
  }

  for(int i=m;i>=0;i--)
  {
    if(dp[n][i])
    {
       cout<<i;
       return 0;
    }
  }
  cout<<-1;



}