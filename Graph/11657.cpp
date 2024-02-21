#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define MAX 1e9
long long  d[501];
using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);

  int n,m;
  vector<tuple<int,int,int>> edge;
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    int a,b,c;
    cin>>a>>b>>c;
    edge.push_back({a,b,c});
  }
  fill(d,d+n+1,MAX);
  d[1]=0;
  bool cycle=false;
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<m;j++)
    {
      int u,v,c;
      tie(u,v,c)=edge[j];
      if(d[u]==MAX)continue;
      if(d[v]>d[u]+c)
      {
        d[v]=d[u]+c;
        if(i==n)
          cycle=true;
      }
    }
  }
  if (cycle)
    cout << -1;
  else
  {
    for (int i = 2; i <= n; i++)
    {
      if (d[i] == MAX)
        cout << -1 << '\n';
      else
        cout << d[i] << '\n';
    }
  }
}