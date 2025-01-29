#include<bits/stdc++.h>

using namespace std;
#define X first  
#define Y second 
pair<int,pair<int,int>> reve[1001][1001];
int dp[1001][1001];
string ans;
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  string a,b;
  cin>>a>>b;
  int alen=a.length();
  int blen=b.length();
  for(int i=1;i<=alen;i++)
  {
    for(int j=1;j<=blen;j++)
    {
      if(a[i-1]==b[j-1])
      {
          if(dp[i-1][j-1]+1>dp[i][j-1])
          {
            dp[i][j]=dp[i-1][j-1]+1;
            reve[i][j]={i-1,{i-1,j-1}};
          }
          else
          {
            dp[i][j]=dp[i][j-1];
            reve[i][j]=reve[i][j-1];
          }
      }
      else
      { 
        if(dp[i-1][j]>dp[i][j-1])
        {
          dp[i][j]=dp[i-1][j];
          reve[i][j]=reve[i-1][j];
        }
        else
        {
          dp[i][j]=dp[i][j-1];
          reve[i][j]=reve[i][j-1];
        }
      }
    }
  }
  int len=dp[alen][blen];
  if(len==0)
  {
    cout<<0;
    return 0;
  }
  pair<int,int> temp={alen,blen};
  while(1)
  {
    auto cur=reve[temp.X][temp.Y];
    ans+=a[cur.X];
    temp={cur.Y.X,cur.Y.Y};
    if(ans.size()==len)break;
  }
  reverse(ans.begin(),ans.end());
  cout<<len<<'\n'<<ans;


}