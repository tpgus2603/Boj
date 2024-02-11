#include<iostream>
#include<vector>

using namespace std;
int n;
vector<int> adj[100];
int arr[100][100];

void dfs(int a,int b)
{
  if(arr[a][b]==0)
  {
    arr[a][b]=1;
    for(auto nxt:adj[b])
      dfs(a,nxt);
  }
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  int temp;
  for(int i=0;i<n;i++)
  { 
    for(int j=0;j<n;j++)
    {
      cin>>temp;
      if(temp==1)
      adj[i].push_back(j);
    }
  }
  for(int i=0;i<n;i++)
  {
    if(!adj[i].empty())
    {
      for(auto nxt:adj[i])
      dfs(i,nxt);
    }
  }
  for(int i=0;i<n;i++)
  {  
    for(int j=0;j<n;j++)
      cout<<arr[i][j]<<' ';
    cout<<'\n';
  }


}