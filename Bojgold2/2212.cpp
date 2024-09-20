#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(int a,int b)
{
  return a>b;
}
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,k;
  vector<int> arr;
  vector<int> dif;
  cin>>n>>k;
  int temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    arr.push_back(temp);
  }
  sort(arr.begin(),arr.end());
  long long sum=0;
  for(int i=1;i<n;i++)
  {
    dif.push_back(arr[i]-arr[i-1]);
    sum+=(arr[i]-arr[i-1]);
  }
  sort(dif.begin(),dif.end(),cmp);
  int idx=0;
  while(1)
  {
    if(idx>=k-1||idx>=n-1)
      break;
    sum-=dif[idx];
    idx++;
  }
  cout<<sum; 


}