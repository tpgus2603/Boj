#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;
int dx[8]={-1,1,0,0,1,1,-1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
#define X first
#define Y second
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int w,h;
  while(1)
  {
    cin>>w>>h;
    if(w==0)
      break;
    bool vis[50][50];
    int arr[50][50];
    int cnt=0;
    for(int i=0;i<h;i++)
    {
      for(int j=0;j<w;j++)
      {
        vis[i][j]=false;
        cin>>arr[i][j];
      }
    }
    for(int i=0;i<h;i++)
    {
      for(int j=0;j<w;j++)
      {
        if(arr[i][j]==0||vis[i][j])continue;
        vis[i][j]==true;
        cnt++;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty())
        {
          auto cur=q.front();
          q.pop();
          for(int dir=0;dir<8;dir++)
          {
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0||nx>=h||ny<0||ny>=w)continue;
            if(arr[nx][ny]==0||vis[nx][ny])continue;
            vis[nx][ny]=true;
            q.push({nx,ny});
          }
        }
      }
    }
    cout<<cnt<<'\n';
    
  }




}