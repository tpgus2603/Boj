#include<iostream>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);

  long long ans=0;
  long long temp=1;

  string str;
  cin>>str;
  int len=str.size();
  stack<char> s;
  for(int i=0;i<len;i++)
  { 
    if(str[i]=='(')
    {
      temp*=2;
      s.push(str[i]);

    }
    else if(str[i]==')')
    {
      if(s.empty()||s.top()!='(')
      {
        cout<<0;
        return 0;
      }
      else
      {
        if(str[i-1]=='(')
        {
          ans+=temp;
          temp/=2;
          s.pop();
        }
        else
        {
          temp/=2;
          s.pop();
        }
      }
    }
    else if(str[i]=='[')
    {
      temp*=3;
      s.push(str[i]);
    }
    else //]ÀÎ °æ¿ì
    {
      if(s.empty()||s.top()!='[')
      {
        cout<<0;
        return 0;
      }
      else
      {
        if(str[i-1]=='[')
        {
          ans+=temp;
          temp/=3;
          s.pop();
        }
        else
        {
          temp/=3;
          s.pop();
        }
      }
    }
  }
  if(!s.empty())
  {
    cout<<0;
    return 0;
  }
  cout<<ans;


}
