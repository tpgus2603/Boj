#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<tuple>
#define X first 
#define Y second
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int sec[201][201];
int arr[201][201];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,k;
  cin>>n>>k;
  queue<tuple<int,int,int>>q; //1.좌표 2.바이러스 값 
  int temp;
  for(int i=1;i<=n;i++)
  { 
    for(int j=1;j<=n;j++)
      {
        sec[i][j]=-1;
        cin>>arr[i][j];
        if(arr[i][j]!=0)
        {
          q.push({i,j,arr[i][j]});
          sec[i][j]=0;
        }
      }
  }
  int S,X,Y;
  cin>>S>>X>>Y;
  //cout<<S<<' '<<X<<' '<<Y<<'\n';
  bool flag=true;
  while(!q.empty()&&flag)
  {
    auto cur=q.front();
    int x,y,v;
    tie(x,y,v)=cur;
    //cout<<x<<' '<<y<<' '<<v<<' '<<'\n';
    q.pop();
    for(int i=0;i<4;i++)
    {
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(nx<=0||nx>n||ny<=0||ny>n) continue;
      if(sec[nx][ny]==(sec[x][y]+1)&&arr[nx][ny]>arr[x][y]);//번호낮은거 증식 
      else if(sec[nx][ny]!=-1)
        continue;
      sec[nx][ny]=sec[x][y]+1;
      if(sec[nx][ny]>S)
      {
        flag=false;
        break;
      }
      arr[nx][ny]=arr[x][y]; //바이러스 옮김
      q.push({nx,ny,arr[nx][ny]});
    }
  }
  cout<<arr[X][Y];
  

  

  



}