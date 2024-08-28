#include<iostream>
#include<queue>
#include<algorithm>

#define ll long long
using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  priority_queue<ll,vector<ll>,greater<ll>>pq;
  ll temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    pq.push(temp);
  }
  int cnt=0;
  while(1)
  { 
    if(cnt==m)break;
    cnt++;
    ll n1=pq.top();
    pq.pop();
    ll n2=pq.top();
    pq.pop();
    pq.push(n1+n2);
    pq.push(n1+n2);
  }
  ll sum=0;
  while(!pq.empty())
  {
    ll a=pq.top();
    pq.pop();
    sum+=a;
  }
  cout<<sum;


}