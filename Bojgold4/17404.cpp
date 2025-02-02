#include<bits/stdc++.h>

using namespace std;
#define X first   //i까지 최소 비용용
#define Y second  //첫번째 인덱스가 택한 색깔

int dp[1001][3]; //빨,초,파 
int arr[1001][3];

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin>>n;
  for(int i=1;i<=1000;i++)
    cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
  int minn=1e9;
  for(int cur=0;cur<3;cur++)
  {
    switch (cur)
    {
    case 0:
      dp[1][0]=arr[1][0];dp[1][1]=1e9;dp[1][2]=1e9;
      break;
    case 1:
      dp[1][0]=1e9;dp[1][1]=arr[1][1];dp[1][2]=1e9;
      break;
    case 2:
      dp[1][0]=1e9;dp[1][1]=1e9;dp[1][2]=arr[1][2];
      break;
    default:
      break;
    }
    for(int i=2;i<=n;i++)
    {
      dp[i][0]=min(dp[i-1][1],dp[i-1][2])+arr[i][0];
      dp[i][1]=min(dp[i-1][0],dp[i-1][2])+arr[i][1];
      dp[i][2]=min(dp[i-1][0],dp[i-1][1])+arr[i][2];
    }
    for(int i=0;i<3;i++)
    {
      if(i==cur)continue;
      minn=min(dp[n][i],minn);
    }
  }
  cout<<minn;
  

}