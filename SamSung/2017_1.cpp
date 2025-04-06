#include<bits/stdc++.h>

using namespace std;
int arr[200][200];
bool vis[200][200];
int n,m;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int ans;

void dfs(int x, int y, int depth,int sum)
{
  if(depth==4)
  {
    ans=max(ans,sum);
    return;
  }
  for(int i=0;i<4;i++)
  {
    int nx=x+dx[i];
    int ny=y+dy[i];
    if(nx<0||nx>=n||ny<0||ny>=m)continue;
    if(vis[nx][ny])continue;
    vis[nx][ny]=true;
    dfs(nx,ny,depth+1,sum+arr[nx][ny]);
    vis[nx][ny]=false;
  }

}

void func(int x,int y,int sum)
{
  if(x+1<n&&y-1>=0&&y+1<m) //ㅗ 가능한경우 
  {
    ans=max(ans,sum+arr[x+1][y-1]+arr[x+1][y]+arr[x+1][y+1]);
  }
  if(y-1>=0&&x-1>=0&&x+1<n)//ㅏ 가능한경우
  {
    ans=max(ans,sum+arr[x][y-1]+arr[x-1][y-1]+arr[x+1][y-1]);
  }
  if(x-1>=0&&y-1>=0&&y+1<m) // ㅜ가능한경우 
  {
    ans=max(ans,sum+arr[x-1][y]+arr[x-1][y+1]+arr[x-1][y-1]);
  }
  if(y+1<m&x-1>=0&&x+1<n) //ㅓ가능한경우
  {
    ans=max(ans,sum+arr[x-1][y+1]+arr[x][y+1]+arr[x+1][y+1]);
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
  for(int x=0;x<n;x++)
  {
    for(int y=0;y<m;y++)
    {
      vis[x][y]=true;
      dfs(x,y,1,arr[x][y]);
      vis[x][y]=false;
      // ㅗ 모양 추가처ㅣㄹ 
      func(x,y,arr[x][y]);

    }
  }
  cout<<ans;

}