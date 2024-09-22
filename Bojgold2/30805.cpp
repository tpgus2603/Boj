#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int A[101];
int B[101];
int main()
{

  ios::sync_with_stdio(0);cin.tie(0);
  vector<int>dp[101][101];
  int n,m;
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>A[i];
  cin>>m;
  for(int i=1;i<=m;i++)
    cin>>B[i];
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(A[i]==B[j]) //A와 B
      {
        auto temp=dp[i-1][j-1];
        while(!temp.empty()&&temp.back()<B[j])
          temp.pop_back();
        temp.push_back(B[j]);
        dp[i][j]=temp;
      } 
      else
      {
        if(dp[i][j-1]<dp[i-1][j])
          dp[i][j]=dp[i-1][j];
        else
          dp[i][j]=dp[i][j-1];
      }
    }
  }
  cout<<dp[n][m].size()<<'\n';
  for(auto temp:dp[n][m])
  {
    cout<<temp<<' ';
  }





}