#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> adj[101];
int dis[101];
int score[101];

int n,m;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  int a,b;
  for(int i=0;i<m;i++)
  {
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i=1;i<=n;i++)
  {
    fill(dis,dis+n+1,-1);
    dis[i]=0;
    queue<int> q;
    q.push(i);
    while(!q.empty())
    {
      auto cur=q.front();
      q.pop();
      for(auto nxt:adj[cur])
      {
        if(dis[nxt]!=-1)continue;
        dis[nxt]=dis[cur]+1;
        q.push(nxt);
      }
    }
    for(int j=0;j<=n;j++)
    {
      if(dis[j]!=-1)
        score[i]+=dis[j];
    }
  }
  int min_n=*min_element(score+1,score+n+1);
  for(int i=1;i<=n;i++)
  {
    if(score[i]==min_n)
      {
         cout<<i;
         break;
      }
  }

}