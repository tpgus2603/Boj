#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int fact(int n)
{
  int mod=1;
  for(int i=n;i>=1;i--)
  {
    mod*=i;
    mod%=10007;
  }
  return mod;
}
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,k;
  cin>>n>>k;
  int ans;
  ans=fact(n)/((fact(n-k)*fact(k))%10007);
  cout<<ans;

}