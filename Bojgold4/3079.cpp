#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long 
using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m; //m명 n개 심사대
  vector<ll> t(n,0);
  ll maxn=0;
  for(int i=0;i<n;i++)
  {
    cin>>t[i];
    maxn=max(maxn,t[i]);
  }
  //최소시간을 매개변수 탐색으로 
  ll st=1;
  ll en=maxn*m; //이 계산에서 오버플로우 주의.. 둘중하나는 ll으로 해야함 
  while(st<en)
  {
    ll mid=(st+en)/2;
    ll total=0;
    bool flag=false;;
    for(int i=0;i<n;i++)
    {
      total+=(mid/t[i]);
      if(total>=m)
      {
        flag=true;
        break;
      }
    }
    if(flag)
      en=mid;
    else
      st=mid+1;
  }
  cout<<en;
}