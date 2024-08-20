#include<algorithm>
#include<vector>
#include<iostream>
#include<cstdint>

using namespace std;


int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int maxn=INT32_MIN;
  int minn=INT32_MAX;
  int n;
  cin>>n;
  vector<int> arr;
  int temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    arr.push_back(temp);
  }
  vector<int>mask;
  int n1,n2,n3,n4; // +,-,X,/   ,0,1,2,3
  cin>>n1>>n2>>n3>>n4;
  for(int i=0;i<n1;i++)
    mask.push_back(0);
  for(int i=0;i<n2;i++)
    mask.push_back(1);
  for(int i=0;i<n3;i++)
    mask.push_back(2);
  for(int i=0;i<n4;i++)
    mask.push_back(3);
  
  do
  {
    int sum=arr[0];
    for(int i=1;i<n;i++)
    {
      if(mask[i-1]==0)
      {
        sum=sum+=arr[i];
      }
      else if(mask[i-1]==1)
      {
        sum=sum-arr[i];
      }
      else if(mask[i-1]==2)
      {
        sum=sum*arr[i];
      }
      else
      {
        sum=sum/arr[i];
      }
    }
    maxn=max(maxn,sum);
    minn=min(minn,sum);
  } while (next_permutation(mask.begin(),mask.end()));
  cout<<maxn<<'\n'<<minn;

}