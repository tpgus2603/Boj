#include<bits/stdc++.h>

#define ll long long 
using namespace std;

bool exist[50002];
int main()
{
  ios::sync_with_stdio(0);  cin.tie(0);
  //50001-5000= 100001
  int g;
  cin>>g;
  for(ll pre=1;pre<=50000;pre++)
  {
    for(ll cur=pre+1;cur<=50001;cur++)
    {
      ll temp=cur*cur-pre*pre;
      if(temp>100000)break;
      if(temp==g)
      {
        exist[cur]=true;
        break;
      }
    }
  }
  bool flag=false;
  for(int i=0;i<=50001;i++)
  {
    if(exist[i])
    {
      cout<<i<<'\n';
      flag=true;
    }
  }
  if(!flag)cout<<-1;

}