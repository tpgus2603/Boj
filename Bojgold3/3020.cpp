#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,h;
  int a,b;
  cin>>n>>h;
    // vector<int> up;
  // vector<int> down; 
  // for(int i=0;i<n/2;i++)
  // {
  //   cin>>a>>b;
  //   up.push_back(a);
  //   down.push_back(b);
  // }
  // sort(up.begin(),up.end());
  // sort(down.begin(),down.end());
  // int cnt=0;
  // int minn=0x7fffffff;
  // for(int i=1;i<=h;i++)
  // {
  //   int a=up.end()-lower_bound(up.begin(),up.end(),i);
  //   int b=down.end()-lower_bound(down.begin(),down.end(),h-i+1);
  //   int sum=a+b;
  //   if(minn>sum)
  //   {
  //     cnt=1;
  //     minn=sum;
  //   }
  //   else if(sum==minn)
  //   {
  //     cnt++;
  //   }
  // }
  // cout<<minn<<' '<<cnt;
  vector<int> imos(h+1,0);
  int temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    if(i%2==0) //석순
    {
      imos[0]++;
      imos[temp+1]--;
    }
    else //종유석
    {
      imos[h-temp+1]++;
    }
  }
  for(int i=1;i<=h;i++)
  {
    imos[i]+=imos[i-1];
  }
  int minn=0x7fffffff;
  int cnt=0;
  for(int i=1;i<=h;i++) //장애물 
  {
    if(minn>imos[i])
    {
      minn=imos[i];
      cnt=1;      
    }
    else if(minn==imos[i])
    {
      cnt++;
    }
  }
  cout<<minn<<' '<<cnt<<'\n';
}