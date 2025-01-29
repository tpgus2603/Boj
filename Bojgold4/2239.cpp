#include <bits/stdc++.h>
using namespace std;


int arr[9][9];
bool flag=false;
bool check(int row,int col,int num) //중복안됨 
{
  //row확인
  for(int i=0;i<9;i++)
    if(arr[row][i]==num)return false;
  //col 확인
  for(int i=0;i<9;i++)
    if(arr[i][col]==num)return false;
  //3x3블럭 확인
  int r,c;
  if(row<3)r=0;if(row>=3&&row<6)r=3;if(row>=6)r=6;
  if(col<3)c=0;if(col>=3&&col<6)c=3;if(col>=6)c=6;
  for(int i=r;i<r+3;i++)
  {
    for(int j=c;j<c+3;j++)
      if(arr[i][j]==num)return false;
  }
  return true;
}

void func(int cur)
{
  if(flag)return;
  if(cur==81)
  {
    for(int i=0;i<9;i++)
    { 
      for(int j=0;j<9;j++)
        cout<<arr[i][j];
      cout<<'\n';
    }
    flag=true;
    return;
  }
  int row=cur/9;
  int col=cur%9;
  if(arr[row][col])
    func(cur+1);
  else
  {
    for(int i=1;i<=9;i++)
    {
      if(!check(row,col,i))continue;
      arr[row][col]=i;
      func(cur+1);
      arr[row][col]=0;
    }
  }
  return;
}


int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  string str;
  for(int i=0;i<9;i++)
  {
    cin>>str;
    for(int j=0;j<9;j++)
      arr[i][j]=str[j]-'0';
  }
  func(0);
}