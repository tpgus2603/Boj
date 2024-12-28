#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  vector<int> arr(n,0);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int maxn=0;
  sort(arr.begin(),arr.end());
  do
  {
    int sum=0;
    for(int i=0;i<n-1;i++)
    {
      sum+=abs(arr[i]-arr[i+1]);
    }
    maxn=max(maxn,sum);
  } while(next_permutation(arr.begin(),arr.end()));
  cout<<maxn;
}