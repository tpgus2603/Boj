#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


bool ispal(const string & str)
{
  int len=str.size();
  bool flag=true;
  for(int i=0;i<len/2;i++)
  {
    if(str[i]!=str[len-1-i])
    {
      flag=false;
      break;
    }
  }
  return flag;
}
bool isppal(const string & str)
{
  int len=str.size();
  bool flag=true;
  for(int i=0;i<len/2;i++)
  {
    if(str[i]!=str[len-1-i])
    {
      auto temp=str;
      temp.erase(temp.begin()+i);
      flag=ispal(temp);
      if(flag)
        return true;
      temp=str;
      temp.erase(temp.begin()+len-1-i);
      flag=ispal(temp);
      if(flag)
        return true;
      return false;
    }
  }
  return flag;
}
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  string str;
  while(t--)
  {
    cin>>str;
    bool flag;
    flag=ispal(str);
    if(flag)
      cout<<0<<'\n';
    else
    {
      flag=isppal(str);
      if(flag)
        cout<<1<<'\n';
      else
        cout<<2<<'\n';
    }
  }
}