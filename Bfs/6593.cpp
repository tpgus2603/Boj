#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
#include<vector>

using namespace std;

int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};


int main()
{
  ios::sync_with_stdio(0);cin.tie(0);

  while(1)
  {
    int minute=-1;
    queue<tuple<int,int,int>> q;
    char arr[31][31][31];
    int dis[31][31][31];
    int l,r,c;
    cin>>l>>r>>c;
    if(l==0&&r==0&&c==0)
    {
      break;
    }
    for(int i=0;i<l;i++)
    {
      for(int j=0;j<r;j++)
      {
        for(int k=0;k<c;k++)
        {
          dis[i][j][k]=-1;
          char temp;
          cin>>temp;
          arr[i][j][k]=temp;
          if(temp=='S')
            {
              q.push({i,j,k});
              dis[i][j][k]=0;
            }
        }
      }
    }
    while(!q.empty())
    {
      auto cur=q.front();q.pop();
      int curx,cury,curz;
      tie(curz,curx,cury)=cur;
      for(int i=0;i<6;i++)
      {
        int nx,ny,nz;
        nx=curx+dx[i];
        ny=cury+dy[i];
        nz=curz+dz[i];
        if(nz<0||nz>=l||nx<0||nx>=r||ny<0||ny>=c)continue;
        if(dis[nz][nx][ny]>=0||arr[nz][nx][ny]=='#')continue;
        q.push({nz,nx,ny});
        dis[nz][nx][ny]=dis[curz][curx][cury]+1;
        if(arr[nz][nx][ny]=='E')
          minute=dis[nz][nx][ny];
      }
    }
    if(minute>=0)
      cout<<"Escaped in "<<minute<<" minute(s)."<<'\n';
    else
      cout<<"Trapped!"<<'\n';
  }



}


