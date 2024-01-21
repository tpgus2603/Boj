#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
char arr[5][5];
bool isused[5][5];
int cnt;
void func(int S,int Y,int r,int c)
{
  if(S+Y==7)
  {
    if(S>Y)
      cnt++;
    return;
  }
  for (int i = 0; i < 4; i++)
  {
    if (r >= 0 && r < 5 && c < 5 && c >= 0 && !isused[r][c])
    {
      isused[r][c] = 1;
      if (arr[r][c] == 'S')
      {
        func(S+1,Y,r+dx[i],c+dy[i]);
      }
      else if (arr[r][c] == 'Y')
      {
        func(S,Y+1,r+dx[i],c+dy[i]);
      }
      isused[r][c]=0;
    }
  }
}

int main()
{
  for(int i=0;i<5;i++)
  {
    string temp;
    cin>>temp;
    int idx=0;
    for(auto x:temp)
      arr[i][idx++]=x;
  }
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<5;j++)
    {
     func(0,0,i,j);
    }
  }
  cout<<cnt;


}