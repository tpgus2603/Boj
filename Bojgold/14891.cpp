#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

string arr[4];


void clock(int n)
{
  char temp=arr[n][7];
  arr[n].pop_back();
  arr[n].insert(0,1,temp);
}
void counterClock(int n){
  char temp=arr[n][0];
  arr[n].erase(0,1);
  arr[n]+=temp;
}
void left(int prev,int dir)
{
  if(prev==0)
    return;
  if(arr[prev][6]==arr[prev-1][2])
    return;
  if(dir==-1)
  {
    left(prev-1,1);
    clock(prev-1);
  }
  else
  {
    left(prev-1,-1);
    counterClock(prev-1);
  }
}
void right(int prev,int dir)
{
  if(prev==3)
    return; 
  if(arr[prev][2]==arr[prev+1][6])
    return;
  if(dir==-1)
  {
    right(prev+1,1);
    clock(prev+1);
  }
  else
  {
    right(prev+1,-1);
    counterClock(prev+1);
  }
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  for(int i=0;i<4;i++)
    cin>>arr[i];
  int k;
  cin>>k;
  for(int i=0;i<k;i++) //dir=1인경우 시계 ,
  {
    int n,dir;
    cin>>n>>dir;
    left(n-1,dir);
    right(n-1,dir);
    if(dir==1)
    {
      clock(n-1);
    }
    else
    {
      counterClock(n-1);
    }
  }
  int sum=0;
  if(arr[0][0]=='1')sum+=1;
  if(arr[1][0]=='1')sum+=2;
  if(arr[2][0]=='1')sum+=4;
  if(arr[3][0]=='1')sum+=8;
  
  cout<<sum;
  
}