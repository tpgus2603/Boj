#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  priority_queue<int,vector<int>, greater<int>> pq;
  int n;
  cin>>n;
  while(n--)
  {
    int x;
    cin>>x;
    if(x>0)
      pq.push(x);
    else
      {
        if(pq.empty())
          cout<<0<<'\n';
        else
        {
          auto ans=pq.top();
          cout<<ans<<'\n';
          pq.pop();
        }
      }
  }


}