#include<iostream>
#include<tuple>
#include<queue>

using namespace std;

int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};

int arr[101][101][101];
int day[101][101][101];
int m,n,h;
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>m>>n>>h;
  int temp;
  queue<tuple<int,int,int>> q;
  for(int i=0;i<h;i++)
  {
    for(int j=0;j<n;j++)
    {
      for(int k=0;k<m;k++)
      {
        cin>>temp;
        arr[j][k][i]=temp;
        if(temp==1)
          q.push({j,k,i});
        if(temp==0) //æ»¿Õ¿∫≥  
          day[j][k][i]=-1;
      }
    }
  }
  while(!q.empty())
  {
    auto cur=q.front();
    q.pop();
    for(int i=0;i<6;i++)
    {
      int curx,cury,curz;
      int nx,ny,nz;
      tie(curx,cury,curz)=cur;
      nx=curx+dx[i];ny=cury+dy[i];nz=curz+dz[i];
      if(nx<0||nx>=n||ny<0||ny>=m||nz<0||nz>=h)continue;
      if(day[nx][ny][nz]>=0)continue;
      q.push({nx,ny,nz});
      day[nx][ny][nz]=day[curx][cury][curz]+1;
    }
  }

  int maxday=0;
    for(int i=0;i<h;i++)
  {
    for(int j=0;j<n;j++)
    {
      for(int k=0;k<m;k++)
      {
        if(day[j][k][i]==-1)
          {
            cout<<-1;
            return 0;
          }
        if(maxday<day[j][k][i])
          maxday=day[j][k][i];
      }
    }
  }
  cout<<maxday;
  return 0;
}