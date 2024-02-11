#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int dp[11][11];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);

  int n,k;
  cin>>n>>k;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>dp[i][j];
    }
  }
  for(int k=0;k<n;k++)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
      }
    }
  }
  vector<int> serch;
  for(int i=0;i<n;i++)
  {
    if(i!=k)
      serch.push_back(i);
  }

  int mi=100000000;
  do
  {
    int prev=k;
    int amt=0;
    for(auto t: serch)
    {
      amt+=dp[prev][t];
      prev=t;
    }
    mi=min(mi,amt);
  } while (next_permutation(serch.begin(),serch.end()));
  cout<<mi;


}