#include<bits/stdc++.h>

#define X first 
#define Y second 
#define INF 1e9
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    //cout<<"t: "<<t<<'\n';
    int w,h;
    cin>>w>>h;
    vector<vector<int>> stime(h,vector<int>(w,-1));
    vector<vector<int>> ftime(h,vector<int>(w,INF));
    vector<string>str;
    string temp;
    queue<pair<int,int>> sq; //상근이 큐 
    queue<pair<int,int>>fq; // 불큐
    for(int i=0;i<h;i++)
    {
      cin>>temp;
      str.push_back(temp);
      for(int j=0;j<w;j++)
      {
        if(temp[j]=='@')
        {
          sq.push({i,j});
          stime[i][j]=0;
        }
        else if(temp[j]=='*')
        {
          fq.push({i,j});
          ftime[i][j]=0;
        }
      }
    }
    //불먼저 이동 후 상근 이동 불은 상근이자리 이동가능 상근이는 불자리 이동불가 
    while(!fq.empty())
    {
      //1 불큐 
      auto cur=fq.front();
      fq.pop();
      for(int dir=0;dir<4;dir++)
      {
        int nx=cur.X+dx[dir];
        int ny=cur.Y+dy[dir];
        if(nx<0||nx>=h||ny<0||ny>=w)continue;
        if(ftime[nx][ny]!=INF||str[nx][ny]=='#')continue;
        ftime[nx][ny]=ftime[cur.X][cur.Y]+1;
        fq.push({nx,ny});
      }
    }
    //상근이 이동 
    bool exist=false;
    int ans=0;
    while(!sq.empty()&&!exist)
    {
      //1 상근
      auto cur=sq.front();
      sq.pop();
      for(int dir=0;dir<4;dir++)
      {
        int nx=cur.X+dx[dir];
        int ny=cur.Y+dy[dir];
        if(nx<0||nx>=h||ny<0||ny>=w)
        {
          exist=true;
          ans=stime[cur.X][cur.Y]+1;
          break;
        }
        if(stime[nx][ny]!=-1||str[nx][ny]=='#')continue;
        stime[nx][ny]=stime[cur.X][cur.Y]+1;
        if(stime[nx][ny]>=ftime[nx][ny])continue;
        sq.push({nx,ny});
      }
    }
    exist? cout<<ans<<'\n': cout<<"IMPOSSIBLE"<<'\n';
  }

}