#include<iostream>
#include<cmath>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;

int arr[10001];
int dp[10001][3];


bool cmp(pair<double,int> a ,pair<double,int> b)
{
  return a.first>b.first;
}
int main()
{
  
  ios::sync_with_stdio(0);cin.tie(0);
  
  vector<pair<double,int>> arr={{2.2,3},{1.1,5},{7.7,4},{9.9,3},{3.3,5}};
    sort(arr.begin(),arr.end(),cmp);
    for(auto k : arr)
      cout<<k.first<<' ';


}