#include<bits/stdc++.h>

using namespace std;



vector<string> split(const string &str ,const string &deli)
{
  vector<string> tokens;
  int st=0;
  int ed=str.find(deli);
  while(ed!=-1)
  {
    if(st!=ed)
      tokens.push_back(str.substr(st,ed-st));
    st=ed+deli.length();
    ed=str.find(deli,st);
  }

  if(st!=str.length())
    tokens.push_back(str.substr(st));
  
  return tokens;



}






int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    set<string> s;
    vector<string> str;
    string temp;
    for(int i=0;i<n;i++)
    {
      cin>>temp;
      s.insert(temp);
      str.push_back(temp);
    }
    bool consist=true;
    for(auto cur: str)
    {
      int len= cur.length();
      for(int i=1;i<len;i++)
      {
        string t=cur.substr(0,i);
        if(s.find(t)!=s.end()) //발견
        {
          consist=false;
          break;
        }
      }
      if(!consist)break;
    }
    consist? cout<<"YES"<<'\n': cout<<"NO"<<'\n';
  }

}