#include<iostream>
#include<sstream>
#include<vector>
#include<string>

using namespace std;


int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  string str,bomb;
  cin>>str;
  cin>>bomb;
  int sb=bomb.length();
  vector<string> tokens;

  string temp;
  for(int i=0;i<str.size();i++)
  {
    temp+=str[i];
    if(temp.length()>=sb)
    {
      string a=temp.substr(temp.length()-sb);
      if(a==bomb)
        temp.erase(temp.length()-sb);
    }
  }
  if(temp.length()==0)
    cout<<"FRULA";
  else
    cout<<temp;


}