#include<iostream>
#include<algorithm>
#include<utility>
#include<queue>
#include<tuple>

#define X first 
#define Y second
using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int tim[100][100];
int vis[100][100];
short arr[100][100];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m,t;
  cin>>n>>m>>t;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
        cin>>arr[i][j];
        tim[i][j]=-1;
    }
  }

  queue<tuple<int,int,int>> q;
  q.push({0,0,0});
  tim[0][0]=0;
  while(!q.empty())
  {
    auto cur=q.front();
    q.pop();
    int x,y,b;
    tie(x,y,b)=cur;
    //cout<<"cur x:"<<y<<"cur y:"<<x<<' '<<tim[x][y]<<'\n';
    if(x==n-1&&y==m-1)break;
    for(int i=0;i<4;i++)
    {
      int nx=x+dx[i];
      int ny=y+dy[i];
      int nb=b;
      if(arr[nx][ny]==2)nb=1;//검 획득 
      if(nx<0||nx>=n||ny<0||ny>=m)continue;
      if(nb==0&&arr[nx][ny]==1)continue;
      if(nb==0&&tim[nx][ny]!=-1)continue;
      if(nb==1&&vis[nx][ny])continue;
      tim[nx][ny]=tim[x][y]+1;
      if(nb==1)vis[nx][ny]=true;
      //if(nb==1)cout<<"x:"<<nx<<"y:"<<ny<<' '<<tim[nx][ny]<<'\n';
      q.push({nx,ny,nb});
    }
  }
  cout<<'\n';
  (tim[n-1][m-1]<=t&&tim[n-1][m-1]!=-1) ? cout<<tim[n-1][m-1]: cout<<"Fail";

}