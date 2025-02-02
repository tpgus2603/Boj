#include<bits/stdc++.h>

using namespace std;
#define X first  
#define Y second  
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
        dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j-1]);
      else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  
  string ans;
  if(dp[alen][blen]==0)
  {
    cout<<0;
    return 0;
  }
  while(alen>0&&blen>0)
  {
    if(dp[alen][blen]==dp[alen][blen-1])blen--;
    else if(dp[alen][blen]==dp[alen-1][blen])alen--;
    else
    {
      ans.push_back(a[alen-1]);
      alen--;blen--;
    }
  }
  reverse(ans.begin(),ans.end());
  cout<<ans.length()<<'\n'<<ans;
}


