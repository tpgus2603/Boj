 #include<iostream>
 #include<utility>
 #include<algorithm>
 #include<queue>
 #include<tuple>

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
#define X first
#define Y second
using namespace std;

int arr[21][21];
int time[21][21];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  pair<int,int> st;

  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cin>>arr[i][j];
      if(arr[i][j]==9)
        st={i,j};
      time[i][j]=-1;
    }
  }
  int ma=0;
  queue<tuple<int,int,int,int>> q; // 좌표,무게,먹은개수
  q.push({st.X,st.Y,2,0});
  time[st.X][st.Y]=0;
  while(!q.empty())
  {
    int x,y,w,s;
    tie(x,y,w,s)=q.front();
    q.pop();
    for(int i=0;i<4;i++)
    {
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(nx<=0||nx>n||ny<=0||ny>n)continue;
      if(arr[nx][ny]>w||time[nx][ny]>=0)continue;
      if(w>arr[nx][ny]) //먹는경우 
      {
        s++;
        if(s==w)
        {
          w++;
          s=0;
        }
        q.push({nx,ny,w,s});
        time[nx][ny]=time[x][y]+1;
        ma=max(ma,time[nx][ny]);
        arr[nx][ny]=0;
        break;
      }
      else // 이동하는경우 
      {
        time[nx][ny]=time[x][y]+1;
        q.push({nx,ny,w,s});
      }

    }
  }
  cout<<ma;

}