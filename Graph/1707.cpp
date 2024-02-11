#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int k,v,e;
  cin>>k;
  while(k--)
  {
    cin>>v>>e; 
    vector<int> adj[v+1];
    int red[v+1]; //1이면 red 0이면 blue
    fill(red+1,red+v+1,-1); 
    int a,b;
    for(int i=0;i<e;i++)
    {
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    for(int i=1;i<=v;i++)
    {
      queue<int> bfs;
      if(red[i]!=-1)continue;
      bfs.push(i);
      red[i]=1;
      while(!bfs.empty())
      {
        int cur=bfs.front();
        bfs.pop();
        for(auto nxt:adj[cur])
        {
          if(red[nxt]!=-1)continue;
          red[nxt]=(red[cur]+1)%2;
          bfs.push(nxt);
        }
      }
    }
    bool ok=true;
    for(int i=1;i<=v;i++)
    {
      int t=red[i];
      for(auto temp:adj[i])
      {
        if(t==red[temp])
          ok=false;
      }
    }
    if(ok)
      cout<<"YES"<<'\n';
    else
      cout<<"NO"<<'\n';

  }


}