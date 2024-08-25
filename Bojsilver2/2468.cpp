#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>
#define X first
#define Y second

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool vis[100][100];
int arr[100][100];
using namespace std;
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  int maxn=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>arr[i][j];
    }
  }

  for(int h=0;h<=100;h++) //내리는 비 높이 
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(arr[i][j]<=h) //높이 이하인경우 방문취급 
          vis[i][j]=true;
        else
          vis[i][j]=false;
      }
    }
    int cnt=0; //영역의 수 
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(vis[i][j])continue;
        vis[i][j]=true;
        queue<pair<int,int>> q;
        q.push({i,j});
        cnt++;
        while(!q.empty())
        {
          auto cur=q.front();
          q.pop();
          for(int dir=0;dir<4;dir++)
          {
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=n)continue;
            if(vis[nx][ny])continue;
            vis[nx][ny]=true;
            q.push({nx,ny});
          }
        }
      }
    }
    maxn=max(maxn,cnt);
  }
  cout<<maxn;






}