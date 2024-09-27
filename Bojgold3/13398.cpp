#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dp[100000][2][2];//dp[i][0][0] 현재까지 현속수 합 [i][1]최대연속수 합 [][][0]=제거안함 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  vector<int> arr;
  int temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    arr.push_back(temp);
  }
  dp[0][0][0]=arr[0];
  dp[0][0][1]=arr[0];
  dp[0][1][0]=arr[0];
  dp[0][1][1]=arr[0];
  for(int i=1;i<n;i++)
  {
    //숫자제거x버전
    if(dp[i-1][0][0]<0)
      dp[i][0][0]=arr[i];
    else
      dp[i][0][0]=dp[i-1][0][0]+arr[i];
    dp[i][1][0]=max(dp[i][0][0],dp[i-1][1][0]);
    //숫자제거버젼
    if(arr[i]<0) //음수인경우 
    {
      if(dp[i-1][0][0]<0) //이전 연속수가 음수 
      {
        dp[i][0][1]=max(dp[i-1][0][0],arr[i]);
      }
      else//이전 연속수가 음수는 아닌경우 
      {
        dp[i][0][1]=max(dp[i-1][0][1]+arr[i],dp[i-1][0][0]);
      }
    }
    else//현재수가 음수는 아닌경우 
    {
      dp[i][0][1]=dp[i-1][0][1]+arr[i]; //
    }
    //cout<<dp[i][0][1]<<'\n';

    dp[i][1][1]=max(dp[i][0][1],dp[i-1][1][1]);
    //cout<<dp[i][1][1]<<'\n';
  }
  cout<<max({dp[n-1][1][1],dp[n-1][1][0]});
}

