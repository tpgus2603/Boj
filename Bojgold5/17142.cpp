#include<bits/stdc++.h>

#define X first 
#define Y second 
using namespace std;

int n,m;
int arr[50][50];
int dist[50][50];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  vector<pair<int,int>> two; //바이러스 놓을수 있는 좌표;
  int cnt=0; //빈칸의 개수 (바이러스 놓는공간도 포함 )
  //0은 빈칸 1은 벽 2는 바이러스 놓는 공간 
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>arr[i][j];
      if(arr[i][j]==2)
        two.push_back({i,j});
      else if(arr[i][j]==0)cnt++;
    }
  }
  vector<int> mask;
  for(int i=0;i<two.size();i++)
  {
    if(i<m)
      mask.push_back(0);
    else
      mask.push_back(1);
  }
  int ans=1e9;
  do
  {
    for(int i=0;i<n;i++)
      fill(dist[i],dist[i]+n,-1);
    int temp=0;//채운 개수
    int maxn=0;//시간
    bool flag=false;
    queue<pair<int,int>> q;
    for(int i=0;i<mask.size();i++)
    {
      if(mask[i]==0)
      {
        q.push({two[i].X,two[i].Y});
        dist[two[i].X][two[i].Y]=0;
      }
    }
    while(!q.empty()&&!flag)
    {
      if(temp==cnt)
      {
        flag=true;
        break;
      }
      auto cur=q.front();
      q.pop();
      for(int dir=0;dir<4;dir++)
      {
        int nx=cur.X+dx[dir];
        int ny=cur.Y+dy[dir];
        if(nx<0||nx>=n||ny<0||ny>=n)continue;
        if(arr[nx][ny]==1||dist[nx][ny]!=-1)continue;
        dist[nx][ny]=dist[cur.X][cur.Y]+1;
        maxn=max(maxn,dist[nx][ny]);
        if(arr[nx][ny]==0)temp++;
        if(temp==cnt)
        {
          flag=true;
          break;
        }
        q.push({nx,ny});
      }
    }
    if(temp==cnt)ans=min(ans,maxn);
  } while (next_permutation(mask.begin(),mask.end()));
  if(ans==1e9)cout<<-1;
  else cout<<ans;

}