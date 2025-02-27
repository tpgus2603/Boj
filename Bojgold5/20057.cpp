#include<bits/stdc++.h>

using namespace std;
#define X first 
#define Y second 
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int n;
int arr[500][500]; //0-based
int ans;

void func (pair<int,int> point,int dir)
{
  int sum=arr[point.X][point.Y];
  int remain=sum;
  int nx,ny;
  //
  int temp;
  int left=(dir+1)%4;
  int right;
  dir==0 ? right=3:right=dir-1;
  //10%
  nx=point.X+dx[dir]+dx[right];ny=point.Y+dy[dir]+dy[right];
  temp=sum*0.1;
  remain-=temp*2;
  if(nx<0||nx>=n||ny<0||ny>=n)ans+=temp;
  else arr[nx][ny]+=temp;
  nx=point.X+dx[dir]+dx[left];ny=point.Y+dy[dir]+dy[left];
  if(nx<0||nx>=n||ny<0||ny>=n)ans+=temp;
  else arr[nx][ny]+=temp;
  //7%
  nx=point.X+dx[right];ny=point.Y+dy[right];
  temp=sum*0.07;
  remain-=temp*2;
  if(nx<0||nx>=n||ny<0||ny>=n)ans+=temp;
  else arr[nx][ny]+=temp;
  nx=point.X+dx[left];ny=point.Y+dy[left];
  if(nx<0||nx>=n||ny<0||ny>=n)ans+=temp;
  else arr[nx][ny]+=temp;
  //2%
  nx=point.X+2*dx[right];ny=point.Y+2*dy[right];
  temp=sum*0.02;
  remain-=temp*2;
  if(nx<0||nx>=n||ny<0||ny>=n)ans+=temp;
  else arr[nx][ny]+=temp;
  nx=point.X+2*dx[left];ny=point.Y+2*dy[left];
  if(nx<0||nx>=n||ny<0||ny>=n)ans+=temp;
  else arr[nx][ny]+=temp;

  //1%
  nx=point.X-dx[dir]+dx[right];ny=point.Y-dy[dir]+dy[right];
  temp=sum*0.01;
  remain-=temp;
  if(nx<0||nx>=n||ny<0||ny>=n)ans+=temp;
  else arr[nx][ny]+=temp;
  nx=point.X-dx[dir]+dx[left];ny=point.Y-dy[dir]+dy[left];
  temp=sum*0.01;
  remain-=temp;
  if(nx<0||nx>=n||ny<0||ny>=n)ans+=temp;
  else arr[nx][ny]+=temp;
  //5%
  nx=point.X+dx[dir]*2;ny=point.Y+dy[dir]*2;
  temp=sum*0.05;
  remain-=temp;
  if(nx<0||nx>=n||ny<0||ny>=n)ans+=temp;
  else arr[nx][ny]+=temp;

  //나머지
  nx=point.X+dx[dir];ny=point.Y+dy[dir];
  if(nx<0||nx>=n||ny<0||ny>=n)ans+=remain;
  else arr[nx][ny]+=remain;
  arr[point.X][point.Y]=0;
}
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>arr[i][j];
  pair<int,int> point={n/2,n/2};

  int time=0;
  int size=1;
  while(point.X!=0||point.Y!=0)
  {
    for(int i=0;i<size;i++) //태풍 크기만큼 이동 
    {
      int dir=time%4;
      point.X=point.X+dx[dir]; //이동 
      point.Y=point.Y+dy[dir];
      func(point,dir);
      if(point.X==0&&point.Y==0)break;
    }
    time++;
    if(time%2==0)size++; //2번이동후 태풍크기 커짐 
  }
  
  cout<<ans;
}