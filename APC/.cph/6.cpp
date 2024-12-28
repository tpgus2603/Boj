#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
#define X first 
#define Y second

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int arr[1001][1001];
int dis[1001][1001];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m,c;
  cin>>n>>m>>c;
  pair<int,int> st;
  cin>>st.X>>st.Y;
  int size=(n+m);
  for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        cin>>arr[i][j];
      }
    }
  for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        dis[i][j]=-1;
      }
    }
    dis[st.X][st.Y]=0;
    queue<pair<int,int>> q;
    q.push({st.X,st.Y});
    int T=arr[st.X][st.Y];
    int temp=0;
    int L=0;
    while(!q.empty())
    {
      auto cur=q.front();
      q.pop();
      L=dis[cur.X][cur.Y];
      if(L>size)break;
      for(int dir=0;dir<4;dir++)
      {
        int nx=cur.X+dx[dir];
        int ny=cur.Y+dy[dir];
        if(nx<=0||nx>n||ny<=0||ny>m)continue;
        if(dis[nx][ny]!=-1||arr[nx][ny]==-1)continue;
        temp+=arr[nx][ny];
        dis[nx][ny]=dis[cur.X][cur.Y]+1;
        q.push({nx,ny});
      }
      T=max(T,temp-(L+1)*c);
    }
  cout<<T;



}