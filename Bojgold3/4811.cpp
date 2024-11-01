#include<iostream>

#define ll long long
using namespace std;

ll dp[31][31];

ll func(int w,int h)
{
  if(w==0&&h==0)return 1;
  if(dp[w][h]!=0)return dp[w][h];
  ll result=0;
  if(w>0)
    result+=func(w-1,h+1);
  if(h>0)
    result+=func(w,h-1);
  dp[w][h]=result;
  return result;
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  while(1)
  {
    int n;
    cin>>n;
    if(n==0)return 0;
    cout<<func(n,0)<<'\n';
  }
}