#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int dp[4001][4001];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  string A,B;
  cin>>A>>B;
  int a=A.size();
  int b=B.size();
  int maxn=0;
  for(int i=1;i<=a;i++)
  {
    for(int j=1;j<=b;j++)
    {
      if(A[i-1]==B[j-1])
      {  
        dp[i][j]=dp[i-1][j-1]+1;
        maxn=max(maxn,dp[i][j]);
      }
    }
  }
  cout<<maxn;

}