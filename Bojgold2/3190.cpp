#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>

#define X first  
#define Y second
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};


int board[101][101]; //0 빈공간,1인경우 사과,2인경우 뱀영역 
char change[10001];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,k;
  cin>>n>>k;
  int x,y,l;
  for(int i=0;i<k;i++)
  {
    cin>>x>>y;
    board[x][y]=1;
  }
  cin>>l;
  int t;
  for(int i=0;i<l;i++)
  {
    cin>>t;
    cin>>change[t];
  }
  deque<pair<int,int>> dq;
  dq.push_back({1,1});
  board[1][1]=2;
  t=1;
  int dir=0;
  while(1)
  {
    auto cur=dq.front();
    int nx=cur.X+dx[dir];
    int ny=cur.Y+dy[dir];
    if(nx<=0||nx>n||ny<=0||ny>n||board[nx][ny]==2)break;
    if(board[nx][ny]==1)
    {
      board[nx][ny]=2; //사과를 지움
    }
    else //사과가 없는경우 
    {
      board[nx][ny]=2;
      auto back=dq.back();
      board[back.X][back.Y]=0;
      dq.pop_back();
    }
    dq.push_front({nx,ny});
    if(change[t])
    {
      if(change[t]=='L')
      {
        if(dir==0)
          dir=3;
        else
          dir--;
      }
      else
      {
        if(dir==3)
          dir=0;
        else
          dir++;
      }
    }
    t++;
  }
  cout<<t;


}