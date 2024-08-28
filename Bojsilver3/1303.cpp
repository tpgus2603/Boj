#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<utility>
using namespace std;
bool vis[100][100];
#define X first 
#define Y second 
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  vector<string> arr;
  string temp;
  for(int i=0;i<m;i++)
  {
    cin>>temp;
    arr.push_back(temp);
  }
  int wsum=0;
  int bsum=0;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(vis[i][j])continue;
      queue<pair<int,int>> q;
      q.push({i,j}); //시작위치 
      vis[i][j]=true;
      int cnt=1;
      while(!q.empty())
      {
        auto cur=q.front();
        q.pop();
        for(int dir=0;dir<4;dir++)
        {
          int nx=cur.X+dx[dir];
          int ny=cur.Y+dy[dir];
          if(nx<0||nx>=m||ny<0||ny>=n)continue;
          if(vis[nx][ny]||arr[i][j]!=arr[nx][ny])continue;
          q.push({nx,ny});
          vis[nx][ny]=true;
          cnt++;
        }
      }
      if(arr[i][j]=='W')
      {
        wsum+=cnt*cnt;
      }
      else{
        bsum+=cnt*cnt;
      }
    }
  }
  cout<<wsum<<' '<<bsum;


}