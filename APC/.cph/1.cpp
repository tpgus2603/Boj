#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  vector<string> str1;
  string temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    str1.push_back(temp);
  }
  vector<string> str2;
  for(int i=0;i<n-1;i++)
  {
    cin>>temp;
    str2.push_back(temp);
  }
  string ans;
  for(auto cur: str1)
  {
    bool flag=false;
    for(auto nxt:str2)
    {
      if(nxt==cur)
      {
        flag=true;
        break;
      }  
    }
    if(!flag)
      ans=cur;
  }
  cout<<ans;



}