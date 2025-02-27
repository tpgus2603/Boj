#include<bits/stdc++.h>

using namespace std;

#define X first 
#define Y second

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int arr[21][21];
bool vis[21][21];
int n;


int bfs(pair<int,int> st,int k1,int k2,int k3,int k4,int num,int k)
{
  //   k1<=x<=k2  k3<=y<=k4 
  int temp=arr[st.X][st.Y];
  vis[st.X][st.Y]=true;
  queue<pair<int,int>> q;
  q.push(st);
  while(!q.empty())
  {
    auto cur=q.front();
    q.pop();
    for(int i=0;i<4;i++)
    {
      int nx=cur.X+dx[i];
      int ny=cur.Y+dy[i];
      if(nx<=0||nx>n||ny<=0||ny>n)continue;
      if(vis[nx][ny])continue;
      if(nx<k1||nx>k2||ny<k3||ny>k4)continue;
      if(num==0) //합이 일정 
      {
        if(nx+ny==k)continue;
      }
      else //차차가 일정 
      {
        if(nx-ny==k)continue;
      }
      temp+=arr[nx][ny];
      vis[nx][ny]=true;
      q.push({nx,ny});
    }
  }
  return temp;
}

int func(int x,int y,int d1,int d2)
{
  int maxn=0;
  int minn=1e9;
  for(int i=1;i<=n;i++)
    fill(vis[i]+1,vis[i]+n+1,false);

  //1영역 0
 int temp=bfs({1,1},1,x+d1-1,1,y,0,x+y);
  maxn=max(temp,maxn);
  minn=min(temp,minn);

  //2영역 1
  temp=bfs({1,n},1,x+d2,y+1,n,1,x-y);
  maxn=max(temp,maxn);
  minn=min(temp,minn);
  //3영역 0
  temp=bfs({n,1},x+d1,n,1,y-d1+d2-1,1,x+d1-y+d1);
  maxn=max(temp,maxn);
  minn=min(temp,minn);

  //4영역 1
  temp=bfs({n,n},x+d2+1,n,y-d1+d2,n,0,x+d2+y+d2);
  maxn=max(temp,maxn);
  minn=min(temp,minn);

  //5영역
  temp=bfs({x,y},1,n,1,n,1,n);
  maxn=max(temp,maxn);
  minn=min(temp,minn);  
  return maxn-minn;

}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  int ans=1e9;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      cin>>arr[i][j];
  }
  for(int x=1;x<=n-2;x++)
  {
    for(int y=2;y<=n-1;y++)
    {
      //d1,d2정하기
      for(int d1=1;d1<=y-1;d1++)
      {
        for(int d2=1;d2<=n-y;d2++)
        {
          if(x+d1+d2>n)continue;
          int temp=func(x,y,d1,d2);
          ans=min(ans,temp);
        }
      } 

    }
  }
  cout<<ans;


}