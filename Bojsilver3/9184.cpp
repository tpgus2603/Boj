#include<iostream>
#include<algorithm>

using namespace std;
int dp[51][51][51];

int func(int a,int b,int c)
{
  if(a<=0||b<=0||c<=0)
    return 1;
  if(dp[a][b][c])return dp[a][b][c];
  else if(a>20||b>20||c>20)
  {
    return dp[a][b][c]=func(20,20,20);
  }
  else if(a<b&&b<c)
    return dp[a][b][c]=func(a,b,c-1)+func(a,b-1,c-1)-func(a,b-1,c);
  else
    return dp[a][b][c]=func(a-1,b,c)+func(a-1,b-1,c)+func(a-1,b,c-1)-func(a-1,b-1,c-1);
}
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  while(1)
  {
    int a,b,c;
    cin>>a>>b>>c;
    if(a==-1&&b==-1&&c==-1)break;
    cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<func(a,b,c)<<'\n';
  }
}