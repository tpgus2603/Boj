#include<iostream>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;
//우선순위가 같거나 높은게 스택에 있으면 뺀다.

int rankof(char a)
{
  switch(a)
  {
    case '(':
      return -1;
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 3;
  }
}

bool is_pop(char a,char b)
{
  int a1=rankof(a);
  int b1=rankof(b);
  if(a1>=b1)
    return true;
  else
    return false;
}


int main()
{
  string str;
  cin>>str;
  string ans;
  stack<char> stk;
  for(int i=0;i<str.length();i++)
  {
    char temp=str[i];
    switch(temp)
    {
      case '(':
        stk.push(temp);
        break;
      case ')': // ( 만날때 까지 전부 넣음 
        while(1)
        {
          char t= stk.top();
          stk.pop();
          if(t=='(')
            break;
          ans+=t;
        }
        break;
      case '+':case '-':
      case '*':case '/':
        while(!stk.empty()&&is_pop(stk.top(),temp))
        {
          ans+=stk.top();
          stk.pop();
        }
        stk.push(temp);
        break;
      default:ans+=temp;
    }
  }
  while(!stk.empty())
  {
    ans+=stk.top();
    stk.pop();
  }
  cout<<ans;
}