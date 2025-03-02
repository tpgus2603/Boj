#include<bits/stdc++.h>

using namespace std;

vector<string> split(const string &str , const string deli)
{
  vector<string>tokens;
  int start=0;
  int end=str.find(deli);
  while(end!=-1)
  {
     if(start!=end)
      tokens.push_back(str.substr(start,end-start));
    start=end+deli.length();
    end=str.find(deli,start);
  }

  if(start!=str.length())
    tokens.push_back(str.substr(start));
  return tokens;
}






int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  auto cur=split("abc def ghi jk"," ");
  cout<<cur.size()<<' ';
  for(auto temp: cur)
  {
    cout<<temp<<' ';
  }


}