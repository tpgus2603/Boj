#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool prim[4000001]; //false인 경우 소수 

bool ispal(string a)
{
  int len=a.size();
  bool pal=true;
  for(int i=0;i<len/2;i++)
  {
    if(a[i]!=a[len-i-1])
    {
      pal=false;
      break;
    }
  }
  return pal;
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  prim[1]=true;
  for(int i=2;i<=2000;i++)
  {
    for(int j=i;i*j<=4000000;j++)
    {
      prim[i*j]=true;
    }
  }
  int n,ans;
  cin>>n;
  while(1)
  {
    if(!prim[n])
    {
      if(ispal(to_string(n)))
      {
        ans=n;
        break;
      }
    }
    n++;
  }
  cout<<ans;

}