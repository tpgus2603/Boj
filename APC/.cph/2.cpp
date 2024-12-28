#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,t;
  cin>>n;
  cin>>t;
  deque<int> dq;
  int temp;
  for(int i=0;i<2*n;i++)
  {
    cin>>temp;
    dq.push_back(temp);
  }
  while(t--)
  {
    int call;
    cin>>call;
    for(int i=1;i<call;i++)
    {
      int ft=dq.front();
      dq.pop_front();
      dq.push_back(ft);
    }
    int ans=dq.front();
    cout<<ans<<' ';
  }

}