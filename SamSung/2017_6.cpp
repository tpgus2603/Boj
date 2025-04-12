#include<bits/stdc++.h>

using namespace std;
int arr[100][100];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,L;
  cin>>n>>L;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>arr[i][j];
    }
  }
  // 행에대해 검사
  int cnt=0;
  for(int r=0;r<n;r++)
  {

    int cur=-1; //최근 경사끝점 좌표 
    int prev=arr[r][0];
    for(int c=1;c<n;c++)
    {
      //1차이나게 큰경우
      if(arr[r][c]-1==prev)
      {
        if(c-L>cur)
          cur=c-1;
        else break;;
      }
      else if(arr[r][c]+1==prev)//1차이나게 작은경우 
      {
        bool flag=true;
        for(int t=c;t<c+L;t++) //현재부터 L칸 확인 
        {
          if(arr[r][t]!=arr[r][c]||t>=n)
          {
            flag=false;
            break;
          }
        }
        if(!flag)break;
        c=c+L-1;
        cur=c;
      } 
      else if(prev!=arr[r][c])break;
      prev=arr[r][c];
      if(c==n-1)
      {
        cnt++;//완주
        //cout<<"row: "<<r<<'\n';
      } 
    }
  }
  //행에대해 검사
  for(int c=0;c<n;c++)
  {

    int cur=-1; //최근 경사끝점 좌표 
    int prev=arr[0][c];
    for(int r=1;r<n;r++)
    {
      //1차이나게 큰경우
      if(arr[r][c]-1==prev)
      {
        if(r-L>cur)
          cur=r-1;
        else break;;
      }
      else if(arr[r][c]+1==prev)//1차이나게 작은경우 
      {
        bool flag=true;
        for(int t=r;t<r+L;t++) //현재부터 L칸 확인 
        {
          if(arr[t][c]!=arr[r][c]||t>=n)
          {
            flag=false;
            break;
          }
        }
        if(!flag)break;
        r=r+L-1;
        cur=r;
      } 
      else if(prev!=arr[r][c])break;
      prev=arr[r][c];
      if(r==n-1)
      {
        cnt++;
        //cout<<"col: "<<c<<'\n';
      }
    }
  }
  cout<<cnt;

}