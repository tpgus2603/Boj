#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<string>

#define X first
#define Y second
using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);

  int n,m;
  vector<string> arr;
  string temp;
  cin>>n>>m;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    arr.push_back(temp);
  }
  int maxn=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(arr[i][j]=='W')continue;
      int dis[n][m];
      for(int i=0;i<n;i++)
      {
        fill(dis[i],dis[i]+m,-1);
      }
      queue<pair<int,int>> q;
      q.push({i,j});
      dis[i][j]=0;
      while(!q.empty())
      {
        auto cur=q.front();
        q.pop();
        for(int dir=0;dir<4;dir++)
        {
          int nx=cur.X+dx[dir];
          int ny=cur.Y+dy[dir];
          if(nx<0||nx>=n||ny<0||ny>=m)continue;
          if(arr[nx][ny]=='W')continue;
          if(dis[nx][ny]!=-1)continue;
          dis[nx][ny]=dis[cur.X][cur.Y]+1;
          maxn=max(maxn,dis[nx][ny]);
          q.push({nx,ny});
        }
      }
    }
  }

  cout<<maxn;

}