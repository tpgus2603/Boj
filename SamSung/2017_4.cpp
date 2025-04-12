#include<bits/stdc++.h>
#define X first 
#define Y second
using namespace std;
int n,m;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  vector<vector<int>> arr(n,vector<int>(m,0));
  vector<pair<int,int>> fire;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
        cin>>arr[i][j]; //1이 벽 2가 불 
      if(arr[i][j]==2)fire.push_back({i,j});
    }
  }

  vector<short> mask(n*m,1);
  for(int i=0;i<3;i++)
    mask[i]=0; 
  int ans=0;

  do
  {
    //방화벽 또는 불이있는 경우 설치불가
    //vector<vector<bool>>vis(n,vector<bool>(m,false));
    vector<vector<int>>temp(n,vector<int>(m,0)); //각 경우마다 체크하는 배열 
    temp=arr;
    int cnt=0; //영역크기 
    bool flag=true;
    for(int i=0;i<n*m;i++)
    {
      if(mask[i]==0) //불에 넣을 좌표
      {
        int x=i/m;
        int y=i%m;
        if(arr[x][y]!=0){
          flag=false;
          break;
        }
        temp[x][y]=1; //벽 추가설치 
      }
    }
    if(!flag)continue;
    queue<pair<int,int>>q;
    for(auto t:fire)
    {
      q.push({t.X,t.Y});
    }
    while(!q.empty())
    {
      auto cur=q.front();
      q.pop();
      for(int i=0;i<4;i++)
      {
        int nx=cur.X+dx[i];
        int ny=cur.Y+dy[i];
        if(nx<0||nx>=n||ny<0||ny>=m)continue;
        if(temp[nx][ny]!=0)continue;
        temp[nx][ny]=2; //불 번짐 
        q.push({nx,ny});
      }
    }
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if(temp[i][j]==0)cnt++;
      }
    }
    ans=max(ans,cnt);
  } while (next_permutation(mask.begin(),mask.end()));
  
  cout<<ans;
}