#include<bits/stdc++.h>

#define X first 
#define Y second 

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int arr[64][64];
using namespace std;
int n;
bool vis[64][64];
void func(pair<int,int> st,int l)
{
  int layers=l/2;
  for(int layer=0;layer<layers;layer++)
  {
    int left=st.Y+layer;
    int right=st.Y+l-1-layer;
    int top=st.X+layer;
    int bot=st.X+l-1-layer;
    vector<int> elements;
    // 위
    for(int i=left;i<right;i++)
      elements.push_back(arr[top][i]);
    //옆
    for(int i=top;i<bot;i++)
      elements.push_back(arr[i][right]);
    //아래
    for(int i=right;i>left;i--)
      elements.push_back(arr[bot][i]);
    //왼쪽
    for(int i=bot;i>=top+1;i--)
      elements.push_back(arr[i][left]);
    rotate(elements.begin(),elements.end()-(l-1-2*layer),elements.end());
    
    int idx=0;
    //위 
    for(int i=left;i<right;i++)
      arr[top][i]=elements[idx++];
    //옆
    for(int i=top;i<bot;i++)
      arr[i][right]=elements[idx++];
    //아래
    for(int i=right;i>left;i--)
      arr[bot][i]=elements[idx++];
    //왼쪽
    for(int i=bot;i>=top+1;i--)
      arr[i][left]=elements[idx++];
  }
  
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int N,Q;
  cin>>N>>Q;
  n=pow(2,N);
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>arr[i][j];
  int L;
  while(Q--)
  {
    cin>>L;
    int l=pow(2,L);
    for(int r=0;r<n;r+=l)
    {
      for(int c=0;c<n;c+=l)
        func({r,c},l);//회전 
    }
    
    vector<pair<int,int>>minus;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        int cnt=0;
        for(int dir=0;dir<4;dir++)
        {
          int nx=i+dx[dir];
          int ny=j+dy[dir];
          if(nx<0||nx>=n||ny<0||ny>=n)continue;
          if(arr[nx][ny]>0)cnt++;
        }
        if(cnt<3&&arr[i][j]>0)minus.push_back({i,j});
      }
    }
    for(auto temp:minus)
    {
      arr[temp.X][temp.Y]--;
    }
  }

  int sum=0;
  int maxn=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      int temp=0;
      sum+=arr[i][j];
      if(vis[i][j]||arr[i][j]==0)continue;
      queue<pair<int,int>>q;
      vis[i][j]=true;
      q.push({i,j});
      temp++;
      while(!q.empty())
      {
        auto cur=q.front();
        q.pop();
        for(int dir=0;dir<4;dir++)
        {
          int nx=cur.X+dx[dir];
          int ny=cur.Y+dy[dir];
          if(nx<0||nx>=n||ny<0||ny>=n)continue;
          if(arr[nx][ny]==0||vis[nx][ny])continue;
          temp++;
          vis[nx][ny]=true;
          q.push({nx,ny});
        }
      }
      maxn=max(temp,maxn);
    }
  }
  cout<<sum<<'\n'<<maxn;

}

