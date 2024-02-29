#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#define X first
#define T second
using namespace std;
bool vis[200001];


int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,k;
  cin>>n>>k;
  queue<pair<int,int>> bfs;
  bfs.push({n,0});
  vis[n]=1;
  int ans=0;
  while(!bfs.empty())
  {
    auto cur= bfs.front();
    bfs.pop();
    if(cur.X==k)
    {
      ans=cur.T;
      break;
    }
    for(int i=0;i<3;i++) //i=0,1 걷기 -1,+1, i=2,순간이동
    {
      int x=cur.X;
      int t=cur.T;
      if(i==0)
      {
        x*=2;
      }
      else if(i==1)
      {
        x--;
        t++;
      }
      else
      {
        x++;
        t++;
      }
      if(x<0||x>200000||vis[x])continue;
      vis[x]=1;
      bfs.push({x,t});
    }
  }
  cout<<ans;

}