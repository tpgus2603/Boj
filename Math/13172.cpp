#include<iostream>
#include<algorithm>

#define ll long long
#define X 1000000007
using namespace std;

ll power(int a, int b)
{
  if(b==1)
    return a;
  if(b%2==0)
  {
    ll temp=power(a,b/2);
    return temp*temp%X;
  }
  else
  {
    ll temp=power(a,b/2);
    return (temp*temp)%X*a%X;
  }

}


int main()
{

  int m;
  cin>>m;
  ll sum=0;
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>b>>a;
    ll ex=power(b,X-2);
    sum+=(a*ex)%X;
  }
  cout<<sum%X;

}