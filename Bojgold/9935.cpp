#include<iostream>
#include<sstream>
#include<vector>
#include<string>

using namespace std;


vector<string> split (const string &s ,const string deli )
{
  vector<string> tokens;
  int start=0;
  int end=s.find(deli);
  while(end!=string::npos)
  {
    tokens.push_back(s.substr(start,end-start));
    start=end+deli.length();
    end=s.find(deli,start);
  }
  tokens.push_back(s.substr(start));
  return tokens;

}


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