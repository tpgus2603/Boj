#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<utility>
#include<iostream>
#include<map>
using namespace std;

vector<string> split(const string & str, const string &deli )
{
  vector<string> tokens;
  int st=0;
  int end=str.find(deli);
  while(end!=-1)
  {
    tokens.push_back(str.substr(st,end-st));
    st=end+deli.length();
    end=str.find(deli,st);
  }
  tokens.push_back(str.substr(st));
  return tokens;

}


int main()
{
    map<int ,int> m;
    cout<<m[4]<<'\n';
    cout<<m[7]<<'\n';
    int cnt=0;
    for(auto k: m)
    {
      cout<<cnt++;
    }


}