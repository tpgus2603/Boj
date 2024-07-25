#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;


vector<string> split(string a,string deli)
{
  vector<string> token;
  int st=0;
  int ed=a.find(deli);
  while(ed!=-1)
  {
    string temp=a.substr(st,ed-st);
    token.push_back(temp);
    st=ed+deli.length();
    ed=a.find(deli,st);
  }
  token.push_back(a.substr(st));

  return token;
}


int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  string str;
  cin>>str;
  vector<string> tokens=split(str,"-");
  vector<int>sum;
  for(auto k :tokens)
  {
    int temp2=0;
    vector<string>temp=split(k,"+");
    for(auto t:temp)
      temp2+=stoi(t);
    sum.push_back(temp2);
  }
  int ans=sum[0];
  for(int i=1;i<sum.size();i++)
    ans-=sum[i];
  cout<<ans;



}