#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define ll long long
using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);

  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<int>arr;
    int temp;
    while(n--)
    {
      cin>>temp;
      arr.push_back(temp);
    }
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(auto k: arr)
    {
      pq.push(k);
    }
    long long sum=0;
    while(pq.size()!=1)
    {
      ll a1=pq.top(); pq.pop();
      ll a2=pq.top();pq.pop();
      sum+=(a1+a2);
      pq.push(a1+a2);
    }
    cout<<sum<<'\n';
  }



}