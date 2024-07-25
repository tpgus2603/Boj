#include<iostream>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

using namespace std;

deque<string> token (const string &str , const string &deli){
  int st=0;
  int ed=str.find(deli);
  deque<string> arr;
  if(str.empty())
    return arr;
  int len=deli.length();
  while(ed!=-1)
  {
    arr.push_back(str.substr(st,ed-st));
    st=ed+len;
    ed=str.find(deli,st);
  }
  arr.push_back(str.substr(st));
  return arr;
}

int main()
{

  ios::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    bool rever=false;
    bool error=false;
    string p,temp;
    int n;
    cin>>p;
    cin>>n;
    cin>>temp;
    temp=temp.substr(1,temp.length()-2);
    deque<string> str= token(temp,",");
    int len=p.size();
    for(int i=0;i<len;i++)
    {
      if(p[i]=='R')
      {
        if(rever==false)
          rever=true;
        else
          rever=false;
      }
      else
      {
        if(str.empty())
        {
          error=true;
          break;
        }
        if(rever==true)
          str.pop_back();
        else
          str.pop_front();
      }
    }
    if(error==true)
    {
      cout<<"error"<<'\n';
      continue;
    }
    if(rever==true)
      reverse(str.begin(),str.end());
    cout << '[';
    int strlen = str.size();
    for (int i = 0; i < strlen; i++)
    {
      cout << str[i];
      if (i == strlen - 1)
        break;
      cout << ',';
    }
    cout << ']' << '\n';
  }


}