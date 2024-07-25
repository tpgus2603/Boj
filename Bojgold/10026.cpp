#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<string>
#define X first 
#define Y second 
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool vis1[100][100];
bool vis2[100][100];
using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  vector<string>board;
  for(int i=0;i<n;i++)
  {
    string temp;
    cin>>temp;
    board.push_back(temp);
  }
  queue<pair<int,int>> q;
  int cnt1=0,cnt2=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(vis1[i][j])continue;
      cnt1++;
      char temp=board[i][j];
      vis1[i][j]=true;
      q.push({i,j});
      while(!q.empty())
      {
        auto cur=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
          int nx=cur.X+dx[i];
          int ny=cur.Y+dy[i];
          if(nx<0||nx>=n||ny<0||ny>=n)continue;
          if(vis1[nx][ny]||board[nx][ny]!=temp)continue;
          q.push({nx,ny});
          vis1[nx][ny]=true;
        }
      }
    }
  }

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(vis2[i][j])continue;
      cnt2++;
      char temp=board[i][j];
      vis2[i][j]=true;
      q.push({i,j});
      while(!q.empty())
      {
        auto cur=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
          int nx=cur.X+dx[i];
          int ny=cur.Y+dy[i];
          if(vis2[nx][ny]||nx<0||nx>=n||ny<0||ny>=n)continue;
          if(board[nx][ny]!=temp)
          {
            if((temp=='R'&&board[nx][ny]=='G')||(temp=='G'&&board[nx][ny]=='R'));
            else continue;
          }
          q.push({nx,ny});
          vis2[nx][ny]=true;
        }
      }
    }
  }
  cout<<cnt1<<' '<<cnt2;


}