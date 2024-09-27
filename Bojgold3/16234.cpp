#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>

#define X first 
#define Y second 


using namespace std;
int n,l,r;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool vis[50][50];
int arr[50][50];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
 cin>>n>>l>>r;
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<n;j++)
    cin>>arr[i][j];
 }
  int day=0;
  while(1)
  {
    //연합 별로 좌표가 들어있는 벡터생성
    vector<vector<pair<int,int>>> unis;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
        vis[i][j]=false;
    }
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(vis[i][j])continue;
        vector<pair<int,int>> uni;
        queue<pair<int,int>> q;
        q.push({i,j});
        uni.push_back({i,j});
        vis[i][j]=true;
        while(!q.empty())
        {
          auto cur=q.front();
          q.pop();
          for(int dir=0;dir<4;dir++)
          {
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=n)continue;
            if(vis[nx][ny])continue;
            int dif=abs(arr[cur.X][cur.Y]-arr[nx][ny]);
            if(dif<l||dif>r)continue;
            vis[nx][ny]=true;
            q.push({nx,ny});
            uni.push_back({nx,ny});
          }
        }
        if(uni.size()>1)
          unis.push_back(uni);
      }
    }
    if(unis.empty())break;
    for(auto temp :unis)
    {
      int sum=0;
      for(auto cur:temp)
      {
        sum+=arr[cur.X][cur.Y];
      }
      int popul=sum/temp.size();
      for(auto cur: temp)
      {
        arr[cur.X][cur.Y]=popul;
      }
    } 
    // for(int i=0;i<n;i++)
    // {
    //   for(int j=0;j<n;j++)
    //     cout<<arr[i][j]<<' ';
    //   cout<<'\n';
    // }
    day++;
  }
  cout<<day;


}