#include<iostream>

#define ll long long
using namespace std;

int b;
int result=-2;
void backcnt(ll cur,int cnt)
{
  if(cur>b)
    return ;
  else if(cur==b)
    {
      result=cnt;
      return ;
    }
  for(int i=0;i<2;i++)
  {
    if(i==0)
      backcnt(cur*2,cnt+1);
    if(i==1)
      backcnt(cur*10+1,cnt+1);
  }
}


int main()
{
  int a;
  cin>>a>>b;
  backcnt(a,0);
  cout<<result+1;

}