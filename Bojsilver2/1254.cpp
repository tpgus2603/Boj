#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool ispal(string str)
{
  int len=str.size();
  bool check=true;
  for(int i=0;i<len/2;i++)
  {
    if(str[i]!=str[len-i-1])
      check=false;
  }
  return check;
}


int main()
{
  string str;
  cin>>str;
  int cur=str.size();
  for(int i=0;!ispal(str);i++)
  {
    str.insert(cur,1,str[i]);
  }
  cout<<str.size();

}