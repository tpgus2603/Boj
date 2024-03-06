#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  string temp;
  set<string> str;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    str.insert(temp);
  }
  vector<string> test;
  for(int i=0;i<m;i++)
  {
    cin>>temp;
    test.push_back(temp);
  } 
  int cnt=0;
  for(auto k:test)
  {
    if(str.count(k)>0)
      cnt++;
  }
  cout<<cnt;


}