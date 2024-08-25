#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int k;
char str[9];
string minn="999999999";
string maxn="0";
bool vis[10];


bool isok(string num,int cnt)
{
  if(str[cnt-1]=='>') return num[cnt-1]>num[cnt];
  else return num[cnt-1]<num[cnt];
}

void func(int cnt,string num)
{
  if(cnt==k+1)
  {
    if(minn>num)minn=num;
    if(maxn<num)maxn=num;
  }
  for(int i=0;i<=9;i++)
  {
    if(vis[i])continue;
    if(cnt==0||isok(num+to_string(i),cnt))
    {
      vis[i]=true;
      func(cnt+1,num+to_string(i));
      vis[i]=false;
    }
  }

}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>k;

  for(int i=0;i<k;i++)
  {
    cin>>str[i];
  }
  func(0,"");
  cout<<maxn<<'\n'<<minn;
}