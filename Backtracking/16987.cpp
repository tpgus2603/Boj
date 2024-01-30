#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

#define X first  //내구도
#define Y second  //무게
using namespace std;

vector<pair<int,int>> arr;

int maxcnt;
int n;
void func(int cur,int cnt)
{
  if(cur==n)
  {
   if(cnt>=maxcnt)
     maxcnt=cnt;
    return;
  }
  if (arr[cur].X > 0)
  {
    for (int i = 0; i < n; i++)
    {
      if(cur!=i&&arr[i].X>0)
      {
        arr[cur].X-=arr[i].Y;
        if(arr[cur].X<=0)cnt++;
        arr[i].X-=arr[cur].Y;
        if(arr[i].X<=0)cnt++;
        func(cur+1,cnt);
        if(arr[cur].X<=0)cnt--;
        arr[cur].X+=arr[i].Y;
        if(arr[i].X<=0)cnt--;
        arr[i].X+=arr[cur].Y;
      }
      else if(i==n-1)
        func(cur+1,cnt);
    }
    
  }
  else
    func(cur+1,cnt);
}


int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    int x,y;  //x=내구도 
    cin>>x>>y;
    arr.push_back({x,y});
  }
  func(0,0);
  cout<<maxcnt;
}