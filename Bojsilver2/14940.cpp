#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

#define X first
#define Y second
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int arr[1001][1001];
int dist[1001][1001];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  pair<int,int> start;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>arr[i][j];
      dist[i][j]=-1;
      if(arr[i][j]==2)
        start={i,j};
    }
  }
  queue<pair<int,int>> q;
  q.push(start);
  dist[start.X][start.Y]=0;
  while(!q.empty())
  {
    auto cur=q.front();
    q.pop();
    for(int i=0;i<4;i++)
    {
      int nx=cur.X+dx[i];
      int ny=cur.Y+dy[i];
      if(dist[nx][ny]!=-1||arr[nx][ny]==0)continue;
      if(nx<=0||nx>n||ny<=0||ny>m)continue;
      q.push({nx,ny});
      dist[nx][ny]=dist[cur.X][cur.Y]+1;
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(arr[i][j]==0)cout<<0<<' ';
      else cout<<dist[i][j]<<' ';
    }
    cout<<'\n';
  }


}