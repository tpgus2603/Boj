#include<bits/stdc++.h>

using namespace std;

bool dp[2001][2001];
int arr[2001];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    dp[i][i]=true;
  }
  for(int i=n;i>=1;i--)
  {
    for(int j=i+1;j<=n;j++)
    {
      if(arr[i]==arr[j])
      {
        if(dp[i+1][j-1]||i+1>j-1)dp[i][j]=true;
      }
    }
  }
  int m;
  cin>>m;
  int s,e;
  for(int i=1;i<=m;i++)
  {
    cin>>s>>e;
    dp[s][e]?cout<<1<<'\n':cout<<0<<'\n';
  }


}