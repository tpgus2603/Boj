#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int cnt;
vector<int> adj[50];
int n;
bool vis[50];

void dfs(int cur)
{
  if(vis[cur])
    return;
  vis[cur]=true;
  for(auto nxt:adj[cur])
  {
    dfs(nxt);
  }
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  int temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    if(temp==-1)continue;
    adj[temp].push_back(i);
  }
  int r;
  cin>>r;
  vis[r]=true;
  for(auto cur: adj[r])
  {
    dfs(cur);
  }
  for(int i=0;i<n;i++)
  {
    if(vis[i])continue;
    if(adj[i].empty())cnt++;
    else
    {
      bool allvis=true;
      for(auto child:adj[i])
      {
        if(!vis[child]) allvis=false;
      }
      if(allvis) cnt++;
    }
    
  }
  cout<<cnt;
}