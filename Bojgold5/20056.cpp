#include<bits/stdc++.h>

using namespace std;

#define M first 
#define S second

int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

vector<tuple<int,int,int>> arr[51][51]; //질량 M 속력 S 방향 d
int n,M,k;

int translate(int nx)
{
  if(nx>n)
  {
    if(nx%n==0)return n;
    else return nx%n;
  }
  if(nx<=0)
  {
    return n-(nx*-1)%n;
  }
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n>>M>>k;
  int r,c,m,s,d;
  for(int i=0;i<M;i++)
  {
    cin>>r>>c>>m>>s>>d;
    arr[r][c].push_back({m,s,d});
  }
  while(k--)
  {
    vector<tuple<int,int,int>> move[51][51]; //이동한 파이볼 배열열
    //각 파이어볼 이동 
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        for(auto cur:arr[i][j])
        {
          tie(m,s,d)=cur;
          int nx=i+dx[d]*s;
          int ny=j+dy[d]*s;
          if(nx<=0||nx>n)nx=translate(nx);
          if(ny<=0||ny>n)ny=translate(ny);
          move[nx][ny].push_back({m,s,d});
        }
        arr[i][j].clear();
      }
    }
    //파이어볼 종합 및 갱신
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        int len=move[i][j].size();
        if(len==0)continue;
        if(len>=2) //파이어볼 두개이상 
        {
          int mtotal=0;
          int stotal=0;
          int cnt=0;
          for(auto cur:move[i][j])
          {
            tie(m,s,d)=cur;
            mtotal+=m;
            stotal+=s;
            if(d%2==0)cnt++;//짝수인경우 카운트 
          }
          mtotal/=5;
          if(mtotal==0)continue;
          stotal/=len;
          if(cnt==len||cnt==0) //모두 짝수 혹은 홀수
          {
            for(int d=0;d<=6;d+=2)
              arr[i][j].push_back({mtotal,stotal,d});
          }
          else
          {
            for(int d=1;d<=7;d+=2)
              arr[i][j].push_back({mtotal,stotal,d});
          }
        }
        else arr[i][j].push_back(move[i][j][0]);
      }
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      for(auto cur:arr[i][j])
      {
        tie(m,s,d)=cur;
        ans+=m;
      }
    }
  }
  cout<<ans;
}