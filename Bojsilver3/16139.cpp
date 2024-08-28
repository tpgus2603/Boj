#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
int dp[200000][26];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);

  string str;
  int q;
  cin>>str;
  cin>>q;
  int len=str.size();
  dp[0][str[0]-'a']++;
  for(int i=1;i<len;i++)
  {
    for(int j=0;j<26;j++)
    {
      dp[i][j]=dp[i-1][j];
    }
    dp[i][str[i]-'a']++;
  }
  char a;
  int l,r;
  while(q--)
  {
    cin>>a>>l>>r;
    if(l==0)
    {
      cout<<dp[r][a-'a']<<'\n';
    }
    else
    {
      cout<<dp[r][a-'a']-dp[l-1][a-'a']<<'\n';
    }
  }

}