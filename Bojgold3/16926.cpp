#include<iostream>
#include<algorithm>

using namespace std;

int arr[300][300];//0-based
int n,m,r;

void rotate(int st)
{

  

  if(st>=min(n,m)/2)return;
  int temp=arr[st][st];
  for(int i=st;i<m-st-1;i++)// 윗 
    arr[st][i]=arr[st][i+1];
  for(int i=st;i<n-st-1;i++) //오른쪽
    arr[i][m-1-st]=arr[i+1][m-1-st];
  for(int i=m-1-st;i>st;i--)//아래                
    arr[n-1-st][i]=arr[n-1-st][i-1];
  for(int i=n-1-st;i>st;i--) //왼쪽
  {
    if(i==st+1)
      arr[i][st]=temp;
    else
      arr[i][st]=arr[i-1][st];
  }
  rotate(st+1);
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>r;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
      cin>>arr[i][j];
  }
  for(int i=0;i<r;i++)
    rotate(0);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
      cout<<arr[i][j]<<' ';
    cout<<'\n';
  }
}
