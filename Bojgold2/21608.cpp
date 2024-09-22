#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>
using namespace std;

#define X first
#define Y second

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int arr[21][21]; //확정된 자리
bool cmp(pair<int,int> a,pair<int,int> b)
{
  if(a.X==b.X)
    return a.Y<b.Y;
  else
    return a.X<b.X;
}
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  set<int> likes[n*n+1];
  vector<int> s;
  int temp;
  int cur;
  for(int i=0;i<n*n;i++)
  {
    cin>>cur;
    s.push_back(cur);
    for(int j=0;j<4;j++)
    {
      cin>>temp;
      likes[cur].insert(temp);
    }
  }
  arr[2][2]=s[0];
  for(int i=1;i<n*n;i++)
  {
    int cur=s[i];
    int cnt[n+1][n+1]; //상하좌우에서 좋아하는 사람수 세기 
    for(int t=1;t<=n;t++)
      fill(cnt[t],cnt[t]+n+1,0);
    int maxn=0;
    for(int r=1;r<=n;r++)
    {
      for(int c=1;c<=n;c++)
      {
        if(arr[r][c]!=0)
        {
          cnt[r][c]=-1;
          continue;
        }
        for(int dir=0;dir<4;dir++)
        {
          int nx=r+dx[dir];
          int ny=c+dy[dir];
          if(nx<1||nx>n||ny<1||ny>n)continue;
          if(likes[cur].find(arr[nx][ny])!=likes[cur].end())cnt[r][c]++;
        }
        maxn=max(maxn,cnt[r][c]);
      }
    }
    vector<pair<int,int>> maxlist;
    for(int r=1;r<=n;r++)
    {
      for(int c=1;c<=n;c++)
      {
        if(cnt[r][c]==maxn)
          maxlist.push_back({r,c});
      }
    }
    if(maxlist.size()==1)
    {
      auto temp=maxlist[0];
      arr[temp.X][temp.Y]=cur;
    }
    else //최대 리스트에 대해 인접 빈칸 수 세기 
    {
      vector<pair<int,int>> near;
      int cnt[n+1][n+1];
      for(int t=1;t<=n;t++)
        fill(cnt[t],cnt[t]+n+1,-1);
      for(auto temp:maxlist)
      {
        cnt[temp.X][temp.Y]=0;
      }  
      int maxn=0;
      for(auto temp: maxlist)
      {
        for(int dir=0;dir<4;dir++)
        {
          int nx=temp.X+dx[dir];
          int ny=temp.Y+dy[dir];
          if(nx<1||nx>n||ny<1||ny>n)continue;
          if(arr[nx][ny]==0)cnt[temp.X][temp.Y]++;
        }
        maxn=max(maxn,cnt[temp.X][temp.Y]);
      }
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
        {
          if(cnt[i][j]==maxn)
            near.push_back({i,j});
        }
      }
      if(near.size()==1)
      {
        arr[near[0].X][near[0].Y]=cur;
      }
      else
      {
        sort(near.begin(),near.end(),cmp);
        arr[near[0].X][near[0].Y]=cur;
      }
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      auto cur=arr[i][j];
      int cnt=0;
      for(int dir=0;dir<4;dir++)
      {
        int nx=i+dx[dir];
        int ny=j+dy[dir];
        if(nx<1||nx>n||ny<1||ny>n)continue;
        if(likes[cur].find(arr[nx][ny])!=likes[cur].end())cnt++;
      }
      switch(cnt)
      {
        case 0:ans+=0;break;
        case 1:ans+=1;break;
        case 2:ans+=10;break;
        case 3:ans+=100;break;
        case 4:ans+=1000;break;
      }
    }
  }
  cout<<ans;

}