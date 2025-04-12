#include<bits/stdc++.h>

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
#define X first 
#define Y second 
using namespace std;
int n,m,t;
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>t;
  vector<vector<int>> src(n,vector<int>(m,0));
  vector<pair<int,int>> wind;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>src[i][j];
      if(src[i][j]==-1)wind.push_back({i,j}); //바람 위치 넣기
    }
  }
  pair<int,int> up=wind[0];
  pair<int,int> down=wind[1];
  while(t--)
  {
    vector<vector<int>> dst;
    dst=src; //딥카피
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if(src[i][j]==-1)continue;
        pair<int,int> cur={i,j};
        int k=src[cur.X][cur.Y]/5; //확산될 값 
        for(int dir=0;dir<4;dir++)
        {
          int nx=cur.X+dx[dir];
          int ny=cur.Y+dy[dir];
          if(nx<0||nx>=n||ny<0||ny>=m)continue;
          if(src[nx][ny]==-1)continue; //돌풍있는곳  
          dst[cur.X][cur.Y]-=k;
          dst[nx][ny]+=k; 
        }
      }
    }
    src=dst; 
    //위에 부분 넣기 
    for(int i=up.X-1;i>0;i--)///왼쪽 x축
      src[i][0]=src[i-1][0];
    for(int i=0;i<m-1;i++)
      src[0][i]=src[0][i+1];
    for(int i=0;i<up.X;i++)
      src[i][m-1]=src[i+1][m-1];
    for(int i=m-1;i>1;i--)
      src[up.X][i]=src[up.X][i-1];
    src[up.X][1]=0;

    for(int i=down.X+1;i<n-1;i++)
      src[i][0]=src[i+1][0];
    for(int i=0;i<m-1;i++)
      src[n-1][i]=src[n-1][i+1];
    for(int i=n-1;i>down.X;i--)
      src[i][m-1]=src[i-1][m-1];
    for(int i=m-1;i>1;i--)
      src[down.X][i]=src[down.X][i-1];
    src[down.X][1]=0;
  }
  int sum=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
        //cout<<src[i][j]<<' ';
        if(src[i][j]==-1)continue;
        sum+=src[i][j];
    }
    //cout<<'\n';
  }
  cout<<sum;

}