#include<iostream>
#include<algorithm>
#include<tuple>
using namespace std;

int lcm(int m , int n)
{
  int lower=min(m,n);
  int lcm=1;
  for(int i=2;i<=lower;i++)
  {
    if(m%i==0&&n%i==0)
    {
      lcm*=i;
      m/=i;
      n/=i;
    }
  }
  lcm=lcm*m*n;
  return lcm;
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    int m,n,x,y;
    cin>>m>>n>>x>>y;
    int ans=-1;
    int upper=lcm(m,n);
    for(int t=x;t<=upper;t+=m)
    {
      if((t%m==x||(t%m==0&&m==x))&&(t%n==y||(t%n==0&&n==y)))
      {
        ans=t;
        break;
      }
    }
    cout<<ans<<'\n';
  }

}