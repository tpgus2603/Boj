#include<bits/stdc++.h>

using namespace std;
#define X first 
#define Y second 
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
string board[12];
bool vis[12][6];
int ans;
void fall()
{

  for(int x=10;x>=0;x--)
  {
    for(int y=0;y<6;y++)
    {
      int nx=x;
      int ny=y;
      if(board[nx][ny]=='.')continue;
      while(nx<11&&board[nx+1][ny]=='.')
      {
        swap(board[nx][ny],board[nx+1][ny]);
        nx++;
      }
    }
  }
}

//bfs로 같은 색깔 체크 , 순회한 좌표들 벡터로 관리 모두 체크해놓기 
bool check(int x, int y)
{
  vector<pair<int,int>> route;
  route.push_back({x,y});
  vis[x][y];
  queue<pair<int,int>> q;
  q.push({x,y});
  int cnt=0;
  char color=board[x][y];
  while(!q.empty())
  {
    auto cur=q.front();
    q.pop();
    for(int i=0;i<4;i++)
    {
      int nx=cur.X+dx[i];
      int ny=cur.Y+dy[i];
      if(nx<0||nx>=12||ny<0||ny>=12)continue;
      if(vis[nx][ny]||board[nx][ny]!=color)continue;
      cnt++;
      vis[nx][ny]=true;
      route.push_back({nx,ny});
      q.push({nx,ny});
    }
  }
  if(cnt>=4)
  {
    for(auto temp:route)
    {
      board[temp.X][temp.Y]='.';
      vis[temp.X][temp.Y]=false;
    }
    return true;
  }
  else
  {
    for(auto temp:route)
    {
      vis[temp.X][temp.Y]=false;
    }
    return false;
  }
}


int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  
  for(int i=0;i<12;i++)
    cin>>board[i];
  bool flag =true;
  while(flag)
  {
    flag=false;
    for(int i=0;i<12;i++)
    {
      for(int j=0;j<6;j++)
      {
        if(board[i][j]=='.')continue;
        if(check(i,j))
          flag=true;
        // if(flag)
        // {
        //   for(int i=0;i<12;i++)
        //     cout<<board[i]<<'\n';
        //   cout<<'\n';
        // }
      }
    }
    if(flag)ans++;
    fall();
  }
  cout<<ans;
}