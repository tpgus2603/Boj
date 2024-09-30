#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#define X first 
#define Y second
int dx[8]={0,-1,-1,-1,0,1,1,1};
int dy[8]={-1,-1,0,1,1,1,0,-1};
using namespace std;
pair<int,int> dia[4]={{-1,-1},{-1,1},{1,1},{1,-1}};
int A[101][101];
bool vis[101][101];
int n,m;
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cin>>A[i][j];
    }
  }
  vector<pair<int,int>> move; //X:방향, Y:이동칸수 
  int a,b;
  for(int i=0;i<m;i++)
  {
    cin>>a>>b;
    move.push_back({a,b});
  }
  int cnt=0;
  for(auto temp: move)
  {
    queue<pair<int,int>> q;
    if(cnt==0) //첫번째 인 경우 비바라기 
    {
      q.push({n,1});
      q.push({n,2});
      q.push({n-1,1});
      q.push({n-1,2});
    }
    else
    {
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
        {
          if(vis[i][j]||A[i][j]<2)continue;
          q.push({i,j});  //구름 영역 큐에넣기
          A[i][j]-=2; 
        }
      }
    }
    for(int i=1;i<=n;i++) //이전 방문칸 초기화 
      for(int j=1;j<=n;j++)
        vis[i][j]=false;
    vector<pair<int,int>> cloud;
    while(!q.empty()) //구름 이동 
    {
      auto cur=q.front();
      q.pop();
      int nx=cur.X;
      int ny=cur.Y;
      for(int i=0;i<temp.Y;i++)
      {
        nx+=(dx[temp.X-1]);
        ny+=(dy[temp.X-1]);
        if(nx==0)nx=n;
        if(nx>n)nx=1;
        if(ny==0)ny=n;
        if(ny>n)ny=1;
      }
      A[nx][ny]+=1; //물의양 증가 
      vis[nx][ny]=true; //구름이 사라진 영역 표시
      cloud.push_back({nx,ny});
    }
    //물복사버그
    for(auto t:cloud)
    {
      for(int k=0;k<4;k++) //대각선 4방향에 대해
      {
        int n1=t.X+dia[k].X;
        int n2=t.Y+dia[k].Y;
        if(n1<1||n1>n||n2<1||n2>n||A[n1][n2]<=0)continue;
        A[t.X][t.Y]++;
      }
    }
    cnt++;
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(vis[i][j]||A[i][j]<2)continue;
      A[i][j]-=2; 
    }
  }
  int sum=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      sum+=A[i][j];
  }
  cout<<sum;

}



