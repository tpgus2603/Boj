#include<iostream>
#include<algorithm>
#include<cmath>

#define ll long long
using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    ll x,y;
    cin>>x>>y;
    ll d =y-x;
    ll n=sqrt(d);
    int ans;
    if(n*n==d)
      ans=2*n-1;
    else if(d-n*n>n)
      ans=2*n+1;
    else
      ans=2*n;
    cout<<ans<<'\n';
  }


}