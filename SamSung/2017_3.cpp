#include<bits/stdc++.h>

using namespace std;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int n,m;
int arr[50][50];
int ans=1;
bool vis[50][50];
void func(int x,int y,int dir)
{
  vis[x][y]=true;
  //cout<<x<<' '<<y<<'\n';
  bool flag=false;
  for(int i=1;i<=4;i++)
  {
    int cur=(dir+4-i)%4;
    int nx=x+dx[cur];
    int ny=y+dy[cur];
    if(nx<0||nx>=n||ny<0||ny>=m)continue;
    if(vis[nx][ny]||arr[nx][ny]==1)continue;
    //cout<<' '<<cur<<' ';
    flag=true;
    ans++;
    func(nx,ny,cur);
    break;
  }
  if(!flag) //못찾은경우 방향 유지후 후진 
  {
    int next=0;
    if(dir==0)next=2;
    else if(dir==2)next=0;
    else if (dir==3)next=1;
    else if(dir=1)next=3;
    int nx=x+dx[next];
    int ny=y+dy[next];
    if(arr[nx][ny]==1)return ;
    func(nx,ny,dir);
  }
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int x,y,dir;
  cin>>n>>m;
  cin>>x>>y>>dir;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>arr[i][j];
    }
  }
  func(x,y,dir);
  cout<<ans;


}