#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#define X first
#define T second
using namespace std;
int tim[200001];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,k;
  cin>>n>>k;
  queue<pair<int,int>> bfs;
  bfs.push({n,0});
  fill(tim,tim+200001,1e9);
  int ans=1e9;
  int cnt=0;
  while(!bfs.empty())
  {
    auto cur= bfs.front();
    bfs.pop();
    if(cur.X==k)
    {
      ans=min(ans,cur.T);
      if(cur.T==ans)
        cnt++;
    }
    if(cur.T>ans)
      break;
    for(int i=0;i<3;i++) 
    {
      int x=cur.X;
      int t=cur.T;
      if(i==0)
        x*=2;
      else if(i==1)
        x--;
      else
        x++;
      t++;
      if(x<0||x>200000)continue;
      if(tim[x]<t)continue;
      tim[x]=t;
      bfs.push({x,t});
    }
  }
  cout<<ans<<'\n';
  cout<<cnt;

}