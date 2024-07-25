#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 1e9
using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,s,temp;
  cin>>n>>s;
  vector<int> arr;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    arr.push_back(temp);
  }
  int right=0;
  int sum=arr[0];
  int mlen=MAX;
  for(int left=0;left<n;left++)
  {
    while(right<n&&sum<s)
    {
      right++;
      sum+=arr[right];
    }
    if(right==n)break; //범위를 넘기는경우 -> s이상이 안되는경우다 
      mlen=min(mlen,right-left+1);
    sum-=arr[left];
  }
  if(mlen==MAX)
    cout<<0;
  else
    cout<<mlen;



}