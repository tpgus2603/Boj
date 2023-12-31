#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>

#define X first
#define Y second

using namespace std;

int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={1,-1,2,-2,2,-2,1,-1};


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int dis[300][300];
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
        dis[i][j]=-1;
    }
    queue<pair<int,int>> q;
    int s1,s2,e1,e2;
    cin>>s1>>s2>>e1>>e2;
    q.push({s1,s2});
    dis[s1][s2]=0;
    while(!q.empty())
    {
      auto cur=q.front();
      q.pop();
      if(cur.X==e1&&cur.Y==e2)
      {
        cout<<dis[cur.X][cur.Y]<<'\n';
        break;
      }
      for(int i=0;i<8;i++)
      {
        int nx=cur.X+dx[i];
        int ny=cur.Y+dy[i];
        if(nx<0||nx>=n||ny<0||ny>=n) continue;
        if(dis[nx][ny]>=0)continue;
        q.push({nx,ny});
        dis[nx][ny]=dis[cur.X][cur.Y]+1;
      }
    }

  }


}