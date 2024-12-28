#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<math.h>
#include<unordered_map>
using namespace std;
int  score[32];
bool sel[32];
unordered_map<char,int> word;
vector<string> arr;

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
    int len=temp.size();
    for(int j=0;j<len;j++)
    {
      word[temp[j]]++;
      score[temp[j]-'A']+=pow(10,len-1-j);
    }
  }
  int give=9;
  int len=word.size();
  for(int i=0;i<len;i++)
  {
    int maxid=0;
    int maxs=0;
    for(int j=0;j<32;j++)
    {
      if(sel[j])continue;
      if(maxs<=score[j])
      { 
         maxs=score[j];
         maxid=j;
      }
    }
    word[maxid+'A']=give--;
    sel[maxid]=true;
  }

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
  cout<<sum;
}