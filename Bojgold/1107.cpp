#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool mask[10];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  int temp;
  for(int i=0;i<m;i++)
  {
    cin>>temp;
    mask[temp]=true;
  }
  int minn=0x7fffffff;
  for(int t=0;t<=1000000;t++)
  {

    string temp=to_string(t);
    bool noskip=true;
    int len=temp.size();
    for(int i=0;i<len;i++)
    {
      if(mask[temp[i]-'0'])
      {
          noskip=false;
          break;
      }
    }
    if(!noskip)continue;
    int sum=len+abs(n-t);
    minn=min(minn,sum);
  }
  int k=abs(n-100);
  minn=min(minn,k);
  cout<<minn;



}