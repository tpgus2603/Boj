#include<iostream>
#include<vector>
#include<string>
#include<regex>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  string str;
  while(t--)
  {
    cin>>str;
    regex temp("(100+1|01)+");
    if(regex_match(str,temp))
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }

}



