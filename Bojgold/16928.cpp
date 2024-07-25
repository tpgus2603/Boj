#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>

#define X first
#define N second
using namespace std;
bool vis[101];
int arr[101];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++)
  {
    int x,y;
    cin>>x>>y;
    arr[x]=y;
  }
  for(int i=0;i<m;i++)
  {
    int u,v;
    cin>>u>>v;
    arr[u]=v;
  }
  queue<pair<int,int>> q;
  q.push({1,0});
  vis[1]=true;
  while(!q.empty())
  {
    auto cur=q.front();
    q.pop();
    if(arr[cur.X]!=0) //뱀이나 사다리인경우 이동 
    {
      cur.X=arr[cur.X];
      vis[cur.X]=true;
    }
      if(cur.X==100)
      {
        cout<<cur.N;
        return 0;
      }
    for(int i=1;i<=6;i++)
    {
      int nx=cur.X+i;
      if(nx>100||vis[nx])continue;
      q.push({nx,cur.N+1});
      vis[nx]=true;
    }

  }




}