#include<iostream>
#include<stack>
#include<algorithm>
#include<utility>
#define X first 
#define Y second 

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
using namespace std;

int arr [51][51];
int change[51][51];
int cnt[51][51];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m,t;
  cin>>n>>m>>t;
  bool check=false;
  pair<int,int> airup;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>arr[i][j];
      change[i][j]=arr[i][j];
      if(arr[i][j]==-1&&!check)
      {
          airup={i,j};
          check=true;
      }
    }
  }
  while(t--)
  {
    for(int i=1;i<=n;i++) //먼지 확산 
    {
      for(int j=1;j<=m;j++)
      {
        pair<int,int>cur={i,j};
        if(arr[i][j]==-1)continue;
        int num=arr[i][j]/5;
        for(int dir=0;dir<4;dir++)
        {
          int nx=cur.X+dx[dir];
          int ny=cur.Y+dy[dir];
          if(nx<=0||nx>n||ny<=0||ny>m)continue;
          if(arr[nx][ny]==-1)continue;
          change[nx][ny]+=num;
          change[cur.X][cur.Y]-=num;
        }
      }
    }
    //공기청정기 입구부터 한칸씩 밀기 
    for(int i=airup.X-1;i>1;i--)
      change[i][1]=change[i-1][1];
    for(int i=1;i<m;i++)
      change[1][i]=change[1][i+1];
    for(int i=1;i<airup.X;i++)
      change[i][m]=change[i+1][m];
    for(int i=m;i>2;i--)
      change[airup.X][i]=change[airup.X][i-1];
    change[airup.X][2]=0;
    
    // 공기청정기 아래 부분 
    for(int i=airup.X+2;i<n;i++)
      change[i][1]=change[i+1][1];
    for(int i=1;i<m;i++)
      change[n][i]=change[n][i+1];
    for(int i=n;i>airup.X+1;i--)
      change[i][m]=change[i-1][m];
    for(int i=m;i>2;i--)
      change[airup.X+1][i]=change[airup.X+1][i-1];
    change[airup.X+1][2]=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        arr[i][j]=change[i][j];
      }
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(arr[i][j]==-1)continue;
      ans+=arr[i][j];
    }
  }
  cout<<ans;




}