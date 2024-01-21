#include<algorithm>
#include<utility>
#include<queue>
#include<iostream>
#include<vector>
#include<string>
#define X first
#define Y second
using namespace std;


bool vis[26][26];
vector<int> arr[26];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};



int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,t;
  cin>>n;
  t=n;
  vector<int> area;
  vector<string> str;
  int idx=0;
  while(t--)
  {
    string a;
    cin>>a;
    for(auto k:a)
      arr[idx].push_back(k-'0');
    idx++;
  }
  queue<pair<int,int>> q;
  int cnt=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(arr[i][j]==0||vis[i][j])continue;
      vis[i][j]=1;
      q.push({i,j});
      cnt++;
      int width=1;
      while(!q.empty())
      {
        auto cur=q.front();q.pop();
        for(int k=0;k<4;k++)
        {
          int nx=cur.X+dx[k];
          int ny=cur.Y+dy[k];
          if(nx<0||nx>=n||ny<0||ny>=n)continue;
          if(arr[nx][ny]==0||vis[nx][ny])continue;
          vis[nx][ny]=1;
          q.push({nx,ny});
          width++;
        }
      }
      area.push_back(width);
    }
  }
  sort(area.begin(),area.end());
  cout<<cnt<<'\n';
  for(auto k:area)
    cout<<k<<'\n';





}