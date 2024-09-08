#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#define X first 
#define Y second
using namespace std;
#define ll long long
ll sum1[1001];
ll sum2[1001];
int n,m;
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t>>n;
  int temp;
  for(int i=1;i<=n;i++)
  {
    cin>>temp;
    sum1[i]=sum1[i-1]+temp;
  }
  cin>>m;
  unordered_map<ll,ll> m1;
  unordered_map<ll,ll> m2;
  for(int i=1;i<=m;i++)
  {
    cin>>temp;
    sum2[i]=sum2[i-1]+temp;
  }
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      m1[sum1[j]-sum1[i]]++;
    }
  }
  for(int i=0;i<m;i++)
  {
    for(int j=i+1;j<=m;j++)
    {
      m2[sum2[j]-sum2[i]]++;
    }
  }

  long long cnt=0;
  for(auto cur:m1)
  {
    if(m2.find(t-cur.X)!=m2.end())
      cnt+=(m2[t-cur.X])*(cur.Y);
  }
  cout<<cnt;

}
