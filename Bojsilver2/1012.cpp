#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
#define X first
#define Y second

using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int bfs(int n, int m,int k)
{
  int cnt=0;
  vector<vector<int>> arr(n ,vector<int>(m,0));
  while(k--)
  {
    int x,y;
    cin>>x>>y;
    arr[x][y]=1;
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(arr[i][j]==0)
        continue;
      queue<pair<int,int>> q;
      q.push({i,j});
      arr[i][j]=0;
      while(!q.empty())
      {
        auto cur = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
          int nx=cur.X+dx[i];
          int ny=cur.Y+dy[i];
          if(nx<0||nx>=n|ny<0||ny>=m)continue;
          if(arr[nx][ny]==0)continue;
          q.push({nx,ny});
          arr[nx][ny]=0;
        }
      }
      cnt++;
    }
  }  

  return cnt;
}


int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    int n,m,k;
    cin>>n>>m>>k;;
    int cnt=bfs(n,m,k);
    cout<<cnt<<'\n';
  }
}