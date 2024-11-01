#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
#define X first 
#define Y second 

#define MAX 10000000
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int time1[50][50];//물전파시간
int time2[50][50]; //고슴도치 전파시간 
using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int r,c;
  cin>>r>>c;
  vector<string> arr;
  string temp;
  for(int i=0;i<r;i++)
  {
    cin>>temp;
    arr.push_back(temp);
  }
  //D:비버 S:고슴도치 .:빈칸 *:물 :x:돌 
  queue<pair<int,int>> q1; //물 전파를 위한 큐
  queue<pair<int,int>> q2; //비버이동을 위한 큐
  pair<int,int> goal;
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      time1[i][j]=-1;
      time2[i][j]=-1;
      if(arr[i][j]=='*')//물
      {
        q1.push({i,j});
        time1[i][j]=0;
      }
      if(arr[i][j]=='S') //고슴도치
      {
        q2.push({i,j});
        time2[i][j]=0;
      }
      if(arr[i][j]=='D')
      {
          goal={i,j};
      }
    }
  }
  while(!q1.empty()) //물이동 
  {
    auto cur=q1.front();
    q1.pop();
    for(int i=0;i<4;i++)
    {
      int nx=cur.X+dx[i];
      int ny=cur.Y+dy[i];
      if(nx<0||nx>=r||ny<0||ny>=c)continue;
      if(arr[nx][ny]=='*'||arr[nx][ny]=='D'||arr[nx][ny]=='X')continue;   //돌,물,비버인경우 
      arr[nx][ny]='*';
      time1[nx][ny]=time1[cur.X][cur.Y]+1;
      q1.push({nx,ny});
    }
  }
  // for(int i=0;i<r;i++)
  // {
  //   for(int j=0;j<c;j++)
  //     cout<<time1[i][j]<<' ';
  //   cout<<'\n';
  // }
  while(!q2.empty())
  {
    auto cur=q2.front();
    q2.pop();
    if(arr[cur.X][cur.Y]=='D')break;
    for(int i=0;i<4;i++)
    {
      int nx=cur.X+dx[i];
      int ny=cur.Y+dy[i];
      if(nx<0||nx>=r||ny<0||ny>=c)continue;
      if(arr[nx][ny]=='X')continue;   //돌인경우  
      if(time2[nx][ny]!=-1)continue; //방문한 경우 
      if(time1[nx][ny]!=-1&&time1[nx][ny]<=time2[cur.X][cur.Y]+1)continue; //물이 먼저찬경우 
      time2[nx][ny]=time2[cur.X][cur.Y]+1;
      q2.push({nx,ny});
    }
  }
  // for(int i=0;i<r;i++)
  // {
  //   for(int j=0;j<c;j++)
  //     cout<<time2[i][j]<<' ';
  //   cout<<'\n';
  // }
  if(time2[goal.X][goal.Y]==-1)
    cout<<"KAKTUS";
  else
    cout<<time2[goal.X][goal.Y];
}