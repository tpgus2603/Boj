
#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<string>
#define X first 
#define Y second
using namespace std;
bool vis[600][600];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  vector<string> board;
  string temp;
  pair<int,int> st;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    if(temp.find("I")!=-1)
    {
      auto idx=temp.find("I");
      st={i,idx};
    }
    board.push_back(temp);
  }
  queue<pair<int,int>> q;
  q.push(st);
  vis[st.X][st.Y]=true;
  int cnt=0;
  while(!q.empty())
  {
    auto cur= q.front();
    q.pop();
    if(board[cur.X][cur.Y]=='P')
      cnt++;
    for(int i=0;i<4;i++)
    {
      int nx=cur.X+dx[i];
      int ny=cur.Y+dy[i];
      if(nx<0||nx>=n||ny<0||ny>=m)continue;
      if(vis[nx][ny]||board[nx][ny]=='X')continue;
      vis[nx][ny]=true;
      q.push({nx,ny});
    }
  }
  if(cnt==0)cout<<"TT";
  else cout<<cnt;
  
}