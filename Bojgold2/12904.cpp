#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  string s;
  string t;
  cin>>s>>t;
  int len1=s.size();
  int len2=t.size();
  while(1)
  {
    if(t[len2-1]=='A')
    {
      t.pop_back();
      len2--;
    }
    else//B인경우
    {
      t.pop_back();
      reverse(t.begin(),t.end());
      len2--;
    }
    if(len2==len1)
      break;
  }
  if(s==t)
    cout<<1;
  else
    cout<<0;

}