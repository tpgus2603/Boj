#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

#define MAX 100000000;
using namespace std;

int dp[201][201];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  int a,b,c;
  
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(i==j)
        dp[i][j]=0;
      else
        dp[i][j]=MAX;
    }
  }
  for(int i=1;i<=m;i++)
  {
    cin>>a>>b>>c;
    dp[a][b]=min(dp[a][b],c);
  }

  for(int k=1;k<=n;k++)
  {
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
      }
    }
  }
  int k=0;
  cin>>k;
  vector<int> fr;
  int temp;
  for(int i=0;i<k;i++)
  {
    cin>>temp;
    fr.push_back(temp);
  }
  
  vector<pair<int,int>> arr;
  for(int i=1;i<=n;i++) //도시기준
  {
    int ma=0;
    for(auto k: fr) //친구들
    {
      ma=max(ma,dp[i][k]+dp[k][i]);
    }
    arr.push_back({ma,i});
  }

  sort(arr.begin(),arr.end());

  int ma=arr[0].first;
  for(auto k:arr)
  {
    if(k.first!=ma)
      break;
    cout<<k.second<<" ";
  }




}