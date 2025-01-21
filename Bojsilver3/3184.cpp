#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
#define X first 
#define Y second 

bool vis[250][250];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int r,c;
  cin>>r>>c;
  vector<string>arr;
  string temp;
  for(int i=0;i<r;i++)
  {
    cin>>temp;
    arr.push_back(temp);
  }
  int on=0,vn=0;
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      if(arr[i][j]=='o')on++;
      if(arr[i][j]=='v')vn++;
    }
  }
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      if(arr[i][j]=='#'||vis[i][j])continue;
      queue<pair<int,int>>q;
      q.push({i,j});
      vis[i][j]=true;
      int o=0,v=0;
      while(!q.empty())
      {
        auto cur= q.front();
        q.pop();
        if(arr[cur.X][cur.Y]=='o')o++;
        if(arr[cur.X][cur.Y]=='v')v++;
        for(int dir=0;dir<4;dir++)
        {
          int nx=cur.X+dx[dir];
          int ny=cur.Y+dy[dir];
          if(nx<0||nx>=r||ny<0||ny>=c)continue;
          if(arr[nx][ny]=='#'||vis[nx][ny])continue;
          vis[nx][ny]=true;
          q.push({nx,ny});
        }
      }
      o>v ? vn-=v :on-=o;
    }
  }
  cout<<on<<' '<<vn<<'\n';




}