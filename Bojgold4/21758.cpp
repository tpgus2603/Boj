#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  vector<int> arr(n,0);
  vector<int> ldp(n,0); //누적합
  vector<int> rdp(n,0); //누적합  
  for(int i=0;i<n;i++) //0-based
    cin>>arr[i];
  ldp[0]=arr[0];
  for(int i=1;i<n;i++)
    ldp[i]=ldp[i-1]+arr[i];
  int maxn=0;
  int left=0;
  int right=1;
  int leftsum=ldp[n-1]-arr[0];
  int rightsum=ldp[n-1];
  while(right<n-1)
  {
    int ls=leftsum-arr[right];
    int rs=rightsum-ldp[right];
    maxn=max(maxn,ls+rs);
    right++;
  }
  fill(rdp.begin(),rdp.end(),0);
  rdp[n-1]=arr[n-1];
  for(int i=n-2;i>=0;i--)
    rdp[i]+=rdp[i+1]+arr[i];
  right=n-1;
  left=n-2;
  rightsum=rdp[0]-arr[n-1];
  leftsum=rdp[0];
  while(left>0)
  {
    int ls=leftsum-rdp[left];
    int rs=rightsum-arr[left];
    maxn=max(maxn,ls+rs);
    left--;
  }
  //집이 벌 사이에 있는경우 집 위치만 결정 
  int mid=1;
  while(mid<n-1)
  {
    int ls=ldp[mid]-arr[0];
    int rs=rdp[mid]-arr[n-1];
    maxn=max(maxn,ls+rs);
    mid++;
  }


  cout<<maxn;

}