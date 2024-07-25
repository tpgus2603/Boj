#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int arr[500][500];
bool vis[500][500];
int n,m,maxn;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void func(int x,int y, int sum,int cnt)
{
  if(cnt==3)
  {
    maxn=max(maxn,sum);
    return;
  }
  for(int i=0;i<4;i++)
  {
    int nx=x+dx[i];
    int ny=y+dy[i];
    if(nx<0||nx>=n||ny<0||ny>=m)continue;
    if(vis[nx][ny])continue;
    vis[nx][ny]=true;
    func(nx,ny,sum+arr[nx][ny],cnt+1);
    if(cnt==1)
      func(x,y,sum+arr[nx][ny],cnt+1);
    vis[nx][ny]=false;
  }
}


int main()
{
 ios::sync_with_stdio(0);cin.tie(0);
 cin>>n>>m;
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<m;j++)
    cin>>arr[i][j];
 }
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<m;j++)
  {
    vis[i][j]=true;
    func(i,j,arr[i][j],0);
    vis[i][j]=false;
  }
 }
 cout<<maxn;




}