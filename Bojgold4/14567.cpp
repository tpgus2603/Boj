#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int> adj[1001]; //u를 선수과목으로 하는 과목 리스트v
int indegree[1001];
int sem[1001];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  int u,v;
  for(int i=0;i<m;i++)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    indegree[v]++; //선수조건 존재 
  }
  fill(sem,sem+n+1,1);
  queue<int> q;
  for(int i=1;i<=n;i++)
  {
    if(indegree[i]==0)
      q.push(i);
  }
  while(!q.empty())
  {
    int cur=q.front();
    q.pop();
    for(auto next:adj[cur])
    {
      indegree[next]--;
      if(indegree[next]==0)
        q.push(next);
      sem[next]=max(sem[next],sem[cur]+1);
    }
  }
  for(int i=1;i<=n;i++)
    cout<<sem[i]<<' ';



}