#include<iostream>
#include<utility>
#include<tuple>
#include<algorithm>
#include<vector>

#define MAX 1e9
using namespace std;

int d[501];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int tc;
  cin>>tc;
  while(tc--)
  {
    int n,m,w;
    cin>>n>>m>>w;
    vector<tuple<int,int,int>> edge; 
    for(int i=0;i<m;i++)
    {
      int s,e,t;
      cin>>s>>e>>t;
      edge.push_back({s,e,t});
      edge.push_back({e,s,t});
    }
    for(int i=0;i<w;i++)
    {
      int s,e,t;
      cin>>s>>e>>t;
      edge.push_back({s,e,t*-1});
    }
    bool cycle=false;
    int cnt=edge.size();
    
      fill(d, d + n + 1, MAX);
      d[1] = 0;
      for (int i = 1; i <= n; i++)
      {

        for (int j = 0; j < cnt; j++)
        {
          int from, to, cost;
          tie(from, to, cost) = edge[j];
          if (d[from] == MAX)
            continue;
          if (d[to] > d[from] + cost)
          {
            d[to] = d[from] + cost;
            if (i == n)
              cycle = true;
          }
        }
      }
    if(cycle)
      cout<<"YES"<<'\n';
    else
      cout<<"NO"<<'\n';


  }


}