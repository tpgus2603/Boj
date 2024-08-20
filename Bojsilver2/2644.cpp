#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> adj[101];
bool vis[101];
int a,b;
int findgoal=-1;
void dfs(int cur,int depth)
{
  if(cur==b)
  {
    findgoal=depth;
    return;
  }
  vis[cur]=true;
  for(auto next:adj[cur])
  {
    if(!vis[next])
      dfs(next,depth+1);
  }

}


int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n; //인원수 
  int num;//타겟 a,b 관계수 num 
  cin>>a>>b;
  cin>>num;
  int x,y;
  for(int i=0;i<num;i++)
  {
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
  }
  vis[a]=true;
  for(auto next:adj[a])
  { 
    if(!vis[next])
     dfs(next,1);
  }
  cout<<findgoal;

}
