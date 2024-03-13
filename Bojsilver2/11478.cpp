#include<iostream>
#include<set>
#include<string>
#include<vector>
using namespace std;

vector<string> split(string str, string deli)
{
  vector<string> result;
  int st=0;
  int end=str.find(deli);
  int len=str.size();
  while(end!=-1)
  {
    result.push_back(str.substr(st,end-st));
    st=end+deli.length();
    end=str.find(st,len);
  }
  result.push_back(str.substr(st));
  return result;

}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  string str;
  cin>>str;
  int strlen=str.size();
  set<string> strset;
  for(int len=1;len<=strlen;len++)
  {
    for(int i=0;i<=strlen-len;i++)
    {
      string temp;
      temp=str.substr(i,len);
      strset.insert(temp);
    }
  }
  cout<<strset.size();
}