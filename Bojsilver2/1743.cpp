#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;
#define X first 
#define Y second
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool vis[101][101];
bool arr[101][101];

int main()
{

  ios::sync_with_stdio(0);cin.tie(0);
  int n,m,k;
  cin>>n>>m>>k;
  int x,y;
  for(int i=0;i<k;i++)
  {
    cin>>x>>y;
    arr[x][y]=true;
  }
  int maxn=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(!arr[i][j]||vis[i][j])continue;
      vis[i][j]=true;
      queue<pair<int,int>> q;
      q.push({i,j});
      int cnt=0;
      while(!q.empty())
      {
        auto cur=q.front();
        q.pop();
        cnt++;
        for(int dir=0;dir<4;dir++)
        {
          int nx=cur.X+dx[dir];
          int ny=cur.Y+dy[dir];
          if(nx<=0||nx>n||ny<=0||ny>m)continue;
          if(!arr[nx][ny]||vis[nx][ny])continue;
          vis[nx][ny]=true;
          q.push({nx,ny});
        }
      }
      maxn=max(maxn,cnt);
    }
  }
  cout<<maxn;


}