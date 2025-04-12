#include<bits/stdc++.h>

using namespace std;
int n;
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  vector<vector<int>>arr(n,vector<int>(n,0));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++) //0-based
      cin>>arr[i][j];
  }
  int ans=1e9;
  vector<int> mask(n,1);
  for(int i=0;i<n/2;i++) //0이면 낮 1이면 밤 
    mask[i]=0;
  do{
    int a=0;
    int b=0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(mask[i]==0&&mask[j]==0)a+=arr[i][j];
        if(mask[i]==1&&mask[j]==1)b+=arr[i][j];
      }
    }
    ans=min(ans,abs(a-b));
  }while(next_permutation(mask.begin(),mask.end()));

  cout<<ans;



}