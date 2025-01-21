#include<bits/stdc++.h>
using namespace std;
#define X first  //시작시간
#define Y second  //종료시간 

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  vector<pair<int,int>> room(n);
  int t,s,e;
  for(int i=0;i<n;i++)
  {
    cin>>t>>s>>e;
    room[i]={s,e};
  }
  sort(room.begin(),room.end());
  //종료시간 기준 최소 힙 
  priority_queue<int,vector<int>,greater<int>> pq;

  int ans=0;
  for(auto temp:room)
  {
    if(!pq.empty()&&pq.top()<=temp.X) 
      pq.pop();
    pq.push(temp.Y);
    ans=max(ans,(int)pq.size());
  }
  cout<<ans;
}

