#include<iostream>
#include<vector>

#define ll long long
using namespace std;

ll dp[100][21]; //dp[i][j]  i번째 수까지 j를 만들 수 있는 경우의수 
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  vector<int> arr;
  int temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    arr.push_back(temp);
  }
  dp[0][arr[0]]=1;  
  for(int i=1;i<n-1;i++)
  {
    int cur=arr[i];
    for(int j=0;j<=20;j++)
    {
      if(j-cur>=0)dp[i][j]+=dp[i-1][j-cur];
      if(j+cur<=20)dp[i][j]+=dp[i-1][j+cur];
    }
  }
  cout<<dp[n-2][arr[n-1]];




}