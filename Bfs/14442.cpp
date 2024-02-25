#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
#include<string>

#define MAX 1e9
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int dist[1001][1001][11];
int arr[1001][1001];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m,k;
  cin>>n>>m>>k;

  string temp;
  for(int i=1;i<=n;i++)
  {
    cin>>temp;
    for(int j=1;j<=m;j++)
    { 
       arr[i][j]=temp[j-1]-'0';
    }
  }
  queue<tuple<int,int,int>> bfs;
  dist[1][1][0]=1;
  bfs.push({1,1,0});
  bool find=false;
  while(!bfs.empty())
  {
    int x,y,flag;
    tie(x,y,flag)=bfs.front(); //벽부순적 있는거면 flag=1 없으면 0
    bfs.pop();
    if(x==n&&y==m)
    { 
        cout<<dist[x][y][flag];
        find=true;
        break;
    }
    for(int i=0;i<4;i++)
    {
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(nx<=0||nx>n||ny<=0||ny>m)continue;
      if(arr[nx][ny]==1)
      {
        if(flag<k) //벽을 부술 수 있는경우 
        {
          if(dist[nx][ny][flag+1]!=0)continue;
          dist[nx][ny][flag+1]=dist[x][y][flag]+1;
          bfs.push({nx,ny,flag+1});
        }
        else continue;
      }
      else //벽을 부수지 않는경우 
      {
          if(dist[nx][ny][flag]!=0)continue;
          dist[nx][ny][flag]=dist[x][y][flag]+1;
          bfs.push({nx,ny,flag});
      }
    }
  }
  if(!find)
    cout<<-1;


}


