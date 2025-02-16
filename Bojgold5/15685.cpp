#include<bits/stdc++.h>

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
bool board[101][101]; //y가 행 x가 열

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);  
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    int x,y,d,g;
    cin>>x>>y>>d>>g;
    vector<int> arr;
    arr.push_back(d);
    while(g--)
    {
      int len=arr.size();
      for(int j=len-1;j>=0;j--)
        arr.push_back((arr[j]+1)%4);
    }
    board[y][x]=true;
    for(auto t:arr)
    {
      x+=dx[t];
      y+=dy[t];
      if(x<0||x>100||y<0||y>100)continue;
      board[y][x]=true;
    }
  }
  int cnt=0;
  for(int i=0;i<=99;i++)
  {
    for(int j=0;j<=99;j++)
    {
      if(board[i][j]&&board[i+1][j]&&board[i][j+1]&&board[i+1][j+1])cnt++;
    }
  }
  cout<<cnt;



}