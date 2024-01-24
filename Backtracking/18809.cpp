#include<iostream>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>
#include<cmath>

#define X first
#define Y second

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};


using namespace std;

int arr[50][50];

int time1[50][50]; //g
int time2[50][50]; //r
int m,n,r,g;
int maxn;
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>g>>r;
  vector<pair<int,int>> two;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>arr[i][j];
      if(arr[i][j]==2)
        two.push_back({i,j});
    }
  }
  int twon=two.size();
  vector<int> mask(twon);
  fill(mask.begin(),mask.end(),3);
  for(int i=0;i<g;i++)
    mask[i]=1;
  for(int i=g;i<g+r;i++)
    mask[i]=2;
  do
  {
    for(int i=0;i<n;i++)
    {
      fill(time1[i],time1[i]+m,-1);
      fill(time2[i],time2[i]+m,-1);
    }

    queue<pair<int,int>> q;

    int cnt=0;
    for(int i=0;i<twon;i++)
    {
      if(mask[i]==1) //g
      {
        q.push({two[i].X,two[i].Y});
        time1[two[i].X][two[i].Y]=0;
      }
      else if(mask[i]==2) //r
      {
        q.push({two[i].X,two[i].Y});
        time2[two[i].X][two[i].Y]=0;
      }
    }
    while (!q.empty())
    {
      auto cur = q.front();
      q.pop();
      for (int dir = 0; dir < 4; dir++)
      {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
          continue;
        if (time1[cur.X][cur.Y] >= 0&&time2[cur.X][cur.Y] == -1) // g가 퍼지는 경우
        {
          if (time1[nx][ny] >= 0 || arr[nx][ny] == 0)
            continue;
          if (time2[nx][ny] != -1 && time1[cur.X][cur.Y] >= time2[nx][ny])
            continue;
          time1[nx][ny] = time1[cur.X][cur.Y] + 1;
          if (time1[nx][ny] == time2[nx][ny])
          {  
            cnt++;
          }
          else
          {  
             q.push({nx, ny});
             time2[nx][ny]=-1;
          }
        }
        else if (time2[cur.X][cur.Y] >= 0&&time1[cur.X][cur.Y]==-1)
        {
          if (time2[nx][ny] >= 0 || arr[nx][ny] == 0)
            continue;
          if (time1[nx][ny] != -1 && time2[cur.X][cur.Y] >= time1[nx][ny])
            continue;
          time2[nx][ny] = time2[cur.X][cur.Y] + 1;
          if (time1[nx][ny] == time2[nx][ny])
          {
              cnt++;    
          }
          else
          {
            q.push({nx, ny});
            time1[nx][ny]=-1;
          }
        }
      }
    }
    if(cnt>=maxn)
      maxn=cnt;
  } while (next_permutation(mask.begin(),mask.end()));
  
  cout<<maxn;


}