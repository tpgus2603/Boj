#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
#define ll long long 
vector<ll> ans;


void func(int locate, ll idx,ll cur)
{
  ans.push_back(cur);
  for(ll i=idx+1;i<=9;i++)
  {
    //cout<<locate<<' ';
    func(locate+1,i,cur+pow(10,locate)*i);
  }
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  for(int i=0;i<=9;i++)
  {
    func(1,i,i);
  }
  sort(ans.begin(),ans.end());
  if(ans.size()-1<n)
    cout<<-1;
  else
    cout<<ans[n];
}