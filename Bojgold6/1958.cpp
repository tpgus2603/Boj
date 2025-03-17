#include<bits/stdc++.h>
using namespace std;
int dp[101][101][101];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string a, b, c;
  cin >> a >> b >> c;
  int alen = a.size(), blen = b.size(), clen = c.size();
  for(int i = 1; i <= alen; i++)
  {
    for(int j = 1; j <= blen; j++)
    {
      for(int k = 1; k <= clen; k++)
      {
        if(a[i-1] == b[j-1] && b[j-1] == c[k-1])
          dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
        else
          dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
      }
    }
  }
  cout << dp[alen][blen][clen]; 


}