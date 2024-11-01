#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,k;
  cin>>n>>k;
  vector<int> arr;
  int temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    arr.push_back(temp);
  }
  vector<int> dif;
  for(int i=1;i<n;i++)
  {
    dif.push_back(arr[i]-arr[i-1]);
  }
  int sum=arr[n-1]-arr[0];
  sort(dif.begin(),dif.end(),greater());
  //k-1개 택 
  for(int i=0;i<k-1;i++)
  {
    sum-=dif[i];
  }
  cout<<sum;


}