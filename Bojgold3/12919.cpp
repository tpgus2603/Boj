#include<iostream>
#include<string>
#include<map>
#include<unordered_set>
#include<algorithm>
using namespace std;

string S;
//map<string,int> vis;
unordered_set<string>vis;
bool solve(const string &cur)
{
  vis.insert(cur);
  if(S==cur)return true;
  if(S.length()>cur.length())return false;
  int len=cur.length();
  if(cur[len-1]=='A')
  {
    string temp=cur.substr(0,len-1);
    if(vis.find(temp)==vis.end())
    {
      if(solve(temp))return true;
    }
  }
  if(cur[0]=='B')
  {
    string temp=cur.substr(1,len-1);
    reverse(temp.begin(),temp.end());
    if(vis.find(temp)==vis.end())
    {
      if(solve(temp))return true;
    }
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  string T;
  cin>>S>>T;
  bool result=solve(T);
  (result ==true) ? cout<<1 :cout<<0;

}