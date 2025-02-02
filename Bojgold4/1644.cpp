#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  if(n==1)
  {
    cout<<0;
    return 0;
  }
  int t=sqrt(n);
  t++;
  vector<bool> prim(n+1,true);
  for(int i=2;i<=t;i++)
  {
    if(!prim[i])continue;
    for(int j=i*i;j<=n;j+=i)
    {
      prim[j]=false;
    }
  }
  vector<int> primn;
  for(int i=2;i<=n;i++)
  {
    if(prim[i])primn.push_back(i);
  }
  int len=primn.size();
  vector<int> sum(len,0);
  sum[0]=primn[0];
  for(int i=1;i<len;i++)
  {
    sum[i]=sum[i-1]+primn[i];
  }
  int left=0,right=0;//합공식 sum[right]-sum[left]+primn[left]
  int cnt=0;
  int temp=0;
  while(left<len&&right<len)
  {
    if(sum[right]-sum[left]+primn[left]<n)
    {
      right++;
    }
    else if(sum[right]-sum[left]+primn[left]==n)
    {
      cnt++;
      right++;
      left++;
    }
    else
    {
      left++;
    }
  }
  cout<<cnt;


}