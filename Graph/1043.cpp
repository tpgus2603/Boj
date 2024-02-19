#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> party[51];
int parent[51];
int find(int u)
{
  if(parent[u]==u)
    return u;
  return parent[u]=find(parent[u]);
}
void merge(int u,int v)
{
  u=find(u);
  v=find(v);
  if(u==v)
    return;
  parent[u]=v;
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  int k;
  cin>>k;
  vector<int>truth;
  while(k--)
  {
    int temp;
    cin>>temp;
    truth.push_back(temp);
  }
  for(int i=1;i<=n;i++)
    parent[i]=i;
  if(!truth.empty())
  {
    int temp=find(truth[0]);
    for(auto k:truth)
      merge(temp,k);
  }
  for(int i=1;i<=m;i++)
  {  
    int num;
    cin>>num;
    int temp;
    num--;
    cin>>temp;
    party[i].push_back(temp);
    while(num--)
    {
      int t;
      cin>>t;
      merge(temp,t);
    }
  }
  int lie=0;
  for(int i=1;i<=m;i++)
  {
    if(!truth.empty())
    {
      if(find(party[i][0])==find(truth[0]))
        continue;
    }
    lie++;
  }
  cout<<lie;


}