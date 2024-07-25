#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  string s;
  cin>>s;
  int cnt=0;
  int prev=s.find("I");
  int next=0;
  int check=0;
  while(1)
  {
    next=s.find("I",prev+1);
    if(next==-1)break;
    if(next-prev==2)
      check++;
    else
    {
      check=0;
    }
    if(check>=n)
      cnt++;
    prev=next;
  }
  cout<<cnt;




}