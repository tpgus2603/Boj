#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
#define ll long long 
int cost[64];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  vector<string> tresh;
  string temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    tresh.push_back(temp);
  }
  vector<int> t;
  for(int i=0;i<6;i++)
  {
    int temp;
    cin>>temp;
    t.push_back(temp);
  }
  cost['P'-'A']=t[0];cost['C'-'A']=t[1];cost['V'-'A']=t[2];
  cost['S'-'A']=t[3];cost['G'-'A']=t[4];cost['F'-'A']=t[5];
  ll sum=0;
  int o;
  cin>>o;
  cost['O'-'A']=o;
  for(auto cur: tresh)
  {
    bool flag=true;
    int size=cur.size();
    for(int i=1;i<size;i++)
    {
      if(cur[i]!=cur[i-1])
      {
        flag=false;
        break;
      }
    }
    ll temp; 
    if(flag) //하나의 쓰레기로 구성된 경우 
    {
      int price=cost[cur[0]-'A'];
      if(o>price)
      {
        temp=price*size;
      }
      else
      {
        temp=o*size;
      }
    }
    else //여러개 쓰레기
    {
      temp=o*size;
    }
    sum+=temp;
  }
  cout<<sum;


}