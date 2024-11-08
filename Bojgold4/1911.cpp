#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

#define X first  
#define Y second 

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,L;
  cin>>n>>L;

  int st,ed;
  vector<pair<int,int>> arr;
  for(int i=0;i<n;i++)
  {
    cin>>st>>ed;
    arr.push_back({st,ed});
  }
  sort(arr.begin(),arr.end());
  
  int over=0,cnt=0;
  for(int i=0;i<n;i++)
  {
    auto cur=arr[i];
    int dif;
    if(over+arr[i-1].Y>cur.X) //이전 초과분이 시작위치를 넘어갈때  
    {
      int temp= over+arr[i-1].Y-cur.X; //
      if(temp>cur.Y-cur.X) //초과분이 현재 웅덩이를 커버할 때 
      {
        over=(temp-(cur.Y-cur.X));
        continue;
      }
      else //초과분이 완전히 커버는 못할 때 
      {
        dif=cur.Y-cur.X-temp;
        over=0;
      }
    }
    else
    {
      dif=cur.Y-cur.X;
      over=0;
    }
    int t=dif/L;
    if(dif%L==0) //나눠 떨어지는 경우
    {
      cnt+=t;
    }
    else
    {
      cnt+=(t+1);
      int temp=L-(dif-L*t);//새로운 널빤지 쓸때 초과분
      if(over==0)
        over=temp; 
    }
  }
  cout<<cnt;


}