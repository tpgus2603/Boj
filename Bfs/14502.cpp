#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
#include<utility>

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

#define X first
#define Y second

using namespace std;

int arr[9][9];
bool vis[9][9];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  vector<pair<int,int>> zero;
  vector<pair<int,int>> virus;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>arr[i][j];
      if(arr[i][j]==0)
        zero.push_back({i,j});
      else if(arr[i][j]==2)
        virus.push_back({i,j});
    }
  }
  int k=zero.size();
  int mask[k];
  for(int i=0;i<=2;i++)
    mask[i]=0;
  for(int i=3;i<k;i++)
    mask[i]=1;
  int ans=0;
  do{
    int board[9][9];
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {  
        board[i][j]=arr[i][j];
        vis[i][j]=0;
      }
    }
    for(int i=0;i<k;i++)
    {
      if(mask[i]==0)
        board[zero[i].X][zero[i].Y]=1;
    }
    queue<pair<int,int>> bfs;
    for(auto temp:virus)
    {
      vis[temp.X][temp.Y]=true;
      bfs.push({temp.X,temp.Y});
    }
    while(!bfs.empty())
    {
      auto cur=bfs.front();
      bfs.pop();
      for(int i=0;i<4;i++)
      {
        int nx=cur.X+dx[i];
        int ny=cur.Y+dy[i];
        if(nx<=0||nx>n||ny<=0||ny>m)continue;
        if(vis[nx][ny]||board[nx][ny]!=0)continue;
        board[nx][ny]=2;
        vis[nx][ny]=true;
        bfs.push({nx,ny});
      }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(board[i][j]==0)
          cnt++;
      }
    }
    ans=max(ans,cnt);
  }while(next_permutation(mask,mask+k));  
  cout<<ans;
}