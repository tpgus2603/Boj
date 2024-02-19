#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>

#define X first
#define Y second
int dx[4]={-1,0,0,1};
int dy[4]={0,1,-1,0};


using namespace std;

int arr[101][101];
int closed[101][101];
int cost[101][101];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  string temp;
  for(int i=1;i<=m;i++)
  {
    cin>>temp;
    for(int j=1;j<=n;j++)
    {
      arr[i][j]=temp[j-1]-'0';
    }
  }
  queue<pair<int,int>> bfs;
  bfs.push({1,1});
  closed[1][1]=1;
  int cos;
  while(!bfs.empty())
  {
    auto cur=bfs.front();
    bfs.pop();
    for(int dir=0;dir<4;dir++)
    {
      int nx=cur.X+dx[dir];
      int ny=cur.Y+dy[dir];
      if(nx<=0||nx>m||ny<=0||ny>n)continue;
      if(arr[nx][ny]==1)
        cos=cost[cur.X][cur.Y]+1;
      else
        cos=cost[cur.X][cur.Y];
      if(!closed[nx][ny])
      {
        cost[nx][ny]=cos;
        closed[nx][ny]=1;
        bfs.push({nx,ny});
      }
      else if(closed[nx][ny]&&cost[nx][ny]>cos)
      {
        cost[nx][ny]=cos;
        bfs.push({nx,ny});
      }
      else
        continue;
    }
  }
    cout<<cost[m][n];


}