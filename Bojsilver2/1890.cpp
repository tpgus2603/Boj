#include<iostream>
#include<algorithm>

#define ll long long
using namespace std;

ll dp[120][120];
ll arr[100][100];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>arr[i][j];
    }
  }
  dp[0][0]=1;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(i==n-1&&j==n-1)break;
      dp[i][j+arr[i][j]]+=dp[i][j];
      dp[i+arr[i][j]][j]+=dp[i][j];
    }
  }
  cout<<dp[n-1][n-1];

}