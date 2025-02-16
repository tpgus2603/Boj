#include<bits/stdc++.h>
using namespace std;

int n,l;
int arr[100][100];


int isXsame(int x,int st,int ed)
{
  for(int i=st;i<ed;i++)
    if(arr[x][st]!=arr[x][i])
      return i;
  return 0;
}
int isYsame(int y,int st,int ed)
{
  for(int i=st;i<ed;i++)
    if(arr[st][y]!=arr[i][y])
      return i;
  return 0;
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n>>l;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>arr[i][j];

  int cnt=0;
  //x축길
  for(int i=0;i<n;i++)
  {
    int cur=0;
    int ed=-1; //경사로 끝점 
    while(1)
    {
      //cout<<cur<<'\n';
      int temp=isXsame(i,cur,n);
      if(temp==0)
      {
        //cout<<"x: "<<i<<'\n';
        cnt++;
        break;
      }
      else
      {
        if(arr[i][cur]-arr[i][temp]==1) //내려가는 
        {
          if(temp+l>n)break;
          int t=isXsame(i,temp,temp+l);
          if(t==0)
          {  
            cur=temp+l-1;
            ed=cur;
          }
          else 
            break;
        } 
        else if(arr[i][cur]-arr[i][temp]==-1) //올라가는 
        {
          if(temp-l<0||temp-l<=ed)break;
          int t=isXsame(i,temp-l,temp);
          if(t==0)
            {
              ed=temp-1;
              cur=temp;
            }
          else
            break;
        }
        else break; //연속하지 않은경우
      }
    }
  }
  //y축길
  for(int i=0;i<n;i++)
  {
    int cur=0;
    int ed=-1;
    while(1)
    {
      int temp=isYsame(i,cur,n);
      //cout<<"y: "<<i<<' '<<temp<<'\n';
      if(temp==0)
      {
        //cout<<"y: "<<i<<'\n';
        cnt++;
        break;
      }
      else
      {
        if(arr[cur][i]-arr[temp][i]==1) //내려가는 
        {
          if(temp+l>n)break;
          int t=isYsame(i,temp,temp+l);
          if(t==0)
          {
             cur=temp+l-1;
             ed=cur;
          }
          else 
            break;
        } 
        else if(arr[cur][i]-arr[temp][i]==-1) //올라가는 
        {
          if(temp-l<0||temp-l<=ed)break;
          int t=isYsame(i,temp-l,temp);
          if(t==0)
          {
              cur=temp;
              ed=cur-1;
          }
          else
            break;
        }
        else break; //연속하지 않은경우
      }
    }
  }
  cout<<cnt;

}