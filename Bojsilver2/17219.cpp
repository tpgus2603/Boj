#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  unordered_map<string,string> mp;
  for(int i=0;i<n;i++)
  {
    string s1,s2;
    cin>>s1>>s2;
    mp.insert({s1,s2});
  }
  vector<string> goal;
  for(int i=0;i<m;i++)
  {
    string temp;
    cin>>temp;
    goal.push_back(temp);
  }
  for(auto temp:goal)
  {
    cout<<mp[temp]<<'\n';
  }
}