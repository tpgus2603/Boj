#include<bits/stdc++.h>

#define X first 
#define Y second

using namespace std;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

int dis[20][20];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  int arr[20][20];
  pair<int,int> st;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {  
      cin>>arr[i][j];
      if(arr[i][j]==9)
      {
        st={i,j};
        arr[i][j]=0;
      }
    }
  }
  for(int i=0;i<n;i++)
    fill(dis[i],dis[i]+n,-1);
  int ans=0;
  dis[st.X][st.Y]=0;
  queue<pair<int,int>> q;
  q.push({st.X,st.Y});
  int cnt=0; //현재 처치한 수 
  int level=2; //현재 레벨
  vector<pair<int,int>> target;
  int k=1e9; //타겟의 거리 
  while(!q.empty())
  {
    auto cur=q.front();
    q.pop();
    int temp=arr[cur.X][cur.Y];
    int d=dis[cur.X][cur.Y];
    if(temp>0&&temp<level&&d<=k) //없앨 몬스터 발견 한 경우
    {
      //cout<<d<<' '<<k<<'\n';
      k=d;
      //cout<<k<<' '<<cur.X<<'\n';
      target.push_back(cur);
    }
    for(int i=0;i<4;i++)
    {
      int nx=cur.X+dx[i];
      int ny=cur.Y+dy[i];
      if(nx<0||nx>=n||ny<0||ny>=n)continue;
      if(arr[nx][ny]>level||dis[nx][ny]!=-1)continue;
      dis[nx][ny]=dis[cur.X][cur.Y]+1;
      if(dis[nx][ny]>k)break;
      q.push({nx,ny});
    }
    if(q.empty()&&!target.empty()) //갱신하기 
    {
      sort(target.begin(),target.end());
        auto cur=target[0];
        cnt++;
        k=1e9;
        if(cnt==level)
        {
          cnt=0;
          level++;
        }
        ans+=dis[cur.X][cur.Y];
        arr[cur.X][cur.Y]=0;
        target.clear();//타겟비우기 
        for(int i=0;i<n;i++) //거리초기화 
          fill(dis[i],dis[i]+n,-1);
        dis[cur.X][cur.Y]=0; //시작위치 조정
        q.push({cur.X,cur.Y});
    }
  }
  cout<<ans;

}
