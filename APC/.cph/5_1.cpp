#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
#define X first 
#define Y second
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,k;
  cin>>n>>k;
  vector<pair<int,int>> eat(3);
  for(int i=0;i<3;i++)
  {
    cin>>eat[i].first>>eat[i].second;
  }
  //마지막에는 1440이랑 빼기 
  int cur=eat[0].Y;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<3;j++)
    {
      if(i!=0&&j==0)
      {
        if(eat[j].X+(1440-cur)>k)
        { 
          cout<<"NO";
          return 0;
        }
        if(k-(1440-cur)>eat[j].Y)
          cur=eat[j].Y;
        else
          cur=(k-(1440-cur));
        continue;
      }
      if(eat[j].X-cur>k)
      { 
        cout<<"NO";
        return 0;
      }
      if(cur+k>eat[j].Y)
        cur=eat[j].Y;
      else
        cur+=k;
    }
  }
  cout<<"YES";

}