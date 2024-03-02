#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#define ll long long
#define X  1000000007
using namespace std;

//map<ll,ll> fibo;
unordered_map<ll,ll>fibo;

ll n;

ll cal( ll n)
{
  if(n==1)
    return 1;
  else if(n==0)
    return 0;
  if(fibo.count(n)>0)
    return fibo[n];

  if(n%2==0)
  {
    ll a=n/2;
    ll b= cal(a);
    ll c=cal(a-1);
    fibo[n]=(b+2*c)*b%X;
    return fibo[n];

  }
  else
  {
    ll a=(n+1)/2;
    ll b= cal(a);
    ll c= cal(a-1);
    fibo[n]=(b*b+c*c)%X;
    return fibo[n];
  }
  
} 

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  ll t=cal(n);
  cout<<t;
}