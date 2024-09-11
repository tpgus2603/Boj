#include<iostream>
#include<utility>
#include<vector>

#define X first 
#define Y second

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,k;
  cin>>n>>k;
  vector<pair<int,int>> arr;
  int temp;
  int len=2*n;
  for(int i=0;i<len;i++)
  {
    cin>>temp;
    arr.push_back({temp,0});
  }
  int t=1;
  int cnt=0;
  while(1)
  {
    auto temp=arr[len-1];
    for(int i=len-1;i>=0;i--) //벨트이동  
    {
      if(i!=0)
        arr[i]=arr[i-1];
      if(i==0)
        arr[i]=temp;
      if(i==n-1)  //n번째 칸에 도착하면 로봇 내림 
        arr[i].Y=0;
    }
    for(int i=n-2;i>=0;i--) //로봇이동 
    {
      if(arr[i].Y==0||arr[i+1].X<=0||arr[i+1].Y>0)continue; 
      arr[i].Y=0; 
      arr[i+1].X--;
      if(arr[i+1].X==0)cnt++;
      arr[i+1].Y=1;
      if(i+1==n-1) //n번째 칸이면 하차 
        arr[i+1].Y=0;
    }
    if(arr[0].X>0) 
    {
        arr[0].Y=1;
        arr[0].X--;
        if(arr[0].X==0)cnt++;
    }
    if(cnt>=k)break;
    t++;
  }
  cout<<t;
}
