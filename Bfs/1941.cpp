#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
#define X first
#define Y second 


using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
string arr[5];
int permute[25];
int cnt;


int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  for(int i=0;i<5;i++)
  {
    string temp;
    cin>>temp;
    arr[i]=temp;
  }
  fill(permute+7,permute+25,1);
  do
  {
    queue<pair<int,int>> q;
    int ispick[5][5]={};
    int vis[5][5]={};
    for(int i=0;i<25;i++)
    {
      if(!permute[i])
      {
          ispick[i/5][i%5]=1;
          if(q.empty())
          {
              q.push({i/5,i%5});
              vis[i/5][i%5]=1;
          }
      }
    }
    int sn=0;
    int yn=0;
    while(!q.empty())
    {
      auto cur=q.front();q.pop();
      if(arr[cur.X][cur.Y]=='S')
        sn++;
      else
        yn++;
      for(int i=0;i<4;i++)
      {
        int nx=cur.X+dx[i];
        int ny=cur.Y+dy[i];
        if(nx<0||nx>=5||ny<0||ny>=5) continue;
        if(vis[nx][ny]||!ispick[nx][ny])continue;
        vis[nx][ny]=1;
        q.push({nx,ny});
      }  
    }
    if(sn>yn&&sn+yn==7)
      cnt++;
  } while (next_permutation(permute,permute+25));
  
    cout<<cnt;


}