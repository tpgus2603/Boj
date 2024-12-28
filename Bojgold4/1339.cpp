#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<math.h>
using namespace std;
unordered_map<char,int> word;
int maxn;
int len;
bool vis[10];
vector<string> arr;
void func(int cur,const string & str )
{
  if(cur==len)
  {
    int sum=0;
    for(auto t: arr)
    {
      int tlen=t.length();
      int temp=0;
      for(int i=0;i<tlen;i++)
      {
        temp+=(word[t[i]]*pow(10,tlen-1-i));
      }
      sum+=temp;
    }
    maxn=max(maxn,sum);
    return;
  }

  for(int i=0;i<10;i++)
  {
    char temp=str[cur];
    if(vis[i])continue;
    word[temp]=i;
    vis[i]=true;
    func(cur+1,str);
    vis[i]=false;
  }
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  string temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    arr.push_back(temp);
    for(int j=0;j<temp.size();j++)
    {
      word[temp[j]]++;
    }
  }
  string str;
  for(auto t :word)
  {
    str+=t.first;
  }
  //cout<<str;
  len=str.size();
  func(0,str);
  cout<<maxn;

}