#include<iostream>
#include<algorithm>
#include<vector>


#define ll long long
using namespace std;
ll gcd(ll a ,ll b)
{
  if(b==0)
    return a;
  else
  {
    return gcd(b,a%b);
  }
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  ll a,b;
  cin>>a>>b;
  int ans=gcd(a,b);
  // for(int i=0;i<ans;i++)
  // {
  //   cout<<1;
  // }
  cout << string(ans, '1');


}