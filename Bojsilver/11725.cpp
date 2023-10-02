#include<iostream>
#include<vector>

using namespace std;

vector<int> adj[100001];
int parent[100001];


void dfs(int cur)
{
  for(auto nxt:adj[cur])
  {
    if(parent[cur]==nxt)continue;
    parent[nxt]=cur;
    dfs(nxt);
  }


}
int main()
{

  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  int n1,n2;
  for(int i=0;i<n-1;i++)
  {
    cin>>n1>>n2;
    adj[n1].push_back(n2);
    adj[n2].push_back(n1);
  }
  dfs(1);
  for(int i=2;i<=n;i++)
    cout<<parent[i]<<'\n';

}