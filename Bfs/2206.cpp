#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
#include<string>

#define MAX 1e9
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int dist1[1001][1001];
int dist2[1001][1001];
int arr[1001][1001];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;

  string temp;
  for(int i=1;i<=n;i++)
  {
    cin>>temp;
    for(int j=1;j<=m;j++)
    { 
       arr[i][j]=temp[j-1]-'0';
       dist1[i][j]=MAX;
       dist2[i][j]=MAX;
    }
  }
  queue<tuple<int,int,int>> bfs;
  dist1[1][1]=1;
  bfs.push({1,1,0});
  while(!bfs.empty())
  {
    int x,y,flag;
    tie(x,y,flag)=bfs.front(); //벽부순적 있는거면 flag=1 없으면 0
    bfs.pop();
    for(int i=0;i<4;i++)
    {
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(nx<=0||nx>n||ny<=0||ny>m)continue;
      if(arr[nx][ny]==1)
      {
        if(flag==0) //벽을 부수는경우
        {
          if(dist2[nx][ny]!=MAX)continue;
          dist2[nx][ny]=dist1[x][y]+1;
          bfs.push({nx,ny,1});
        }
        else continue;
      }
      else //벽을 부수지 않는경우 
      {
        if(flag==0)
        { 
          if(dist1[nx][ny]!=MAX)continue;
          dist1[nx][ny]=dist1[x][y]+1;
          bfs.push({nx,ny,0});
        }
        else
        {
          if(dist2[nx][ny]!=MAX)continue;
          dist2[nx][ny]=dist2[x][y]+1;
          bfs.push({nx,ny,1});
        }
      }
    }
  }
  if(dist1[n][m]==MAX&&dist2[n][m]==MAX)
    cout<<-1;
  else
    cout<<min(dist1[n][m],dist2[n][m]);


}


// int bfs() {
//   for (int i = 0; i < n; ++i)
//     for (int j = 0; j < m; ++j)
//       dist[i][j][0] = dist[i][j][1] = -1;
//   dist[0][0][0] = dist[0][0][1] = 1;
//   queue<tuple<int, int, int>> q;
//   q.push({0,0,0});
//   while (!q.empty()) {
//     int x, y, broken;
//     tie(x, y, broken) = q.front();
//     if(x == n-1 && y == m-1) return dist[x][y][broken];
//     q.pop();
//     int nextdist = dist[x][y][broken] + 1;
//     for (int dir = 0; dir < 4; ++dir) {
//       int nx = x + dx[dir];
//       int ny = y + dy[dir];
//       if(OOB(nx, ny)) continue;      
//       if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
//         dist[nx][ny][broken] = nextdist;
//         q.push({nx, ny, broken});
//       }      
//       // (nx, ny)를 부수는 경우
//       if (!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1) {
//         dist[nx][ny][1] = nextdist;
//         q.push({nx, ny, 1});
//       }      
//     }
//   }
//   return -1;
// }