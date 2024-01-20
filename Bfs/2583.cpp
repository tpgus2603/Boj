#include<algorithm>
#include<utility>
#include<queue>
#include<iostream>
#include<vector>
#define X first
#define Y second
using namespace std;


bool vis[101][101];
int arr[101][101];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};



int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int m,n,k;
  cin>>m>>n>>k;
  vector<int> area;
  while(k--)
  {
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    for(int i=y1;i<y2;i++)
    {
      for(int j=x1;j<x2;j++)
      {
        arr[i][j]=-1;  //직사각형 영역 -1로 표시 
      }
    }
  }
  queue<pair<int,int>> q;
  int cnt=0;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(arr[i][j]==-1||vis[i][j])continue;
      vis[i][j]=1;
      q.push({i,j});
      cnt++;
      int width=1;
      while(!q.empty())
      {
        auto cur=q.front();q.pop();
        for(int k=0;k<4;k++)
        {
          int nx=cur.X+dx[k];
          int ny=cur.Y+dy[k];
          if(nx<0||nx>=m||ny<0||ny>=n)continue;
          if(arr[nx][ny]==-1||vis[nx][ny])continue;
          vis[nx][ny]=1;
          q.push({nx,ny});
          width++;
        }
      }
      area.push_back(width);
    }
  }
  sort(area.begin(),area.end());
  cout<<cnt<<'\n';
  for(auto k:area)
    cout<<k<<" ";





}