#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>

#define X first
#define Y second
using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

int arr[100][100];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>arr[i][j];
    }
  }
  int t=0;
  while(1)
  {
    bool ncz=false; 
    queue<pair<int,int>> aq; //air공간에 대한 bfs
    int avis[n][m];
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
        avis[i][j]=0;
    }
    aq.push({0,0});
    avis[0][0]=1;
    while(!aq.empty()) //공기 접촉 공간 
    {
      auto cur=aq.front();
      aq.pop();
      for(int i=0;i<4;i++)
      {
        int nx=cur.X+dx[i];
        int ny=cur.Y+dy[i];
        if(nx<0||nx>=n||ny<0||ny>=m)continue;
        if(avis[nx][ny]||arr[nx][ny]==1)continue;
        aq.push({nx,ny});
        avis[nx][ny]=1;
      }
    }
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        int cnt=0;
        if(arr[i][j]==1)
        {
          ncz=true;
          for(int dir=0;dir<4;dir++)
          {
            int nx=i+dx[dir];
            int ny=j+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m)continue;
            if(avis[nx][ny]==1)cnt++;
          }
        }
        if(cnt>=2)
          arr[i][j]=0;
      }
    }
    if(!ncz)
      break;
    t++;
  }
    cout<<t;




}