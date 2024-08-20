#include<iostream>
#include<algorithm>
#include<cstdint>
#include<vector>

using namespace std;
int arr[20][20];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>arr[i][j];
    }
  }
  vector<int> mask;
  for(int i=0;i<n/2;i++)
    mask.push_back(0);
  for(int i=0;i<n/2;i++)
    mask.push_back(1);
  int minn=INT32_MAX;
  do
  {
    int start=0;
    int link=0;
    for(int i=0;i<20;i++)
    {
      for(int j=0;j<20;j++)
      {
        if(mask[i]==0&&mask[j]==0)
          start+=arr[i][j];
        else if(mask[i]==1&&mask[j]==1)
          link+=arr[i][j];
      }
    }
    minn=min(minn,abs(start-link));
  } while (next_permutation(mask.begin(),mask.end()));
  cout<<minn;
}