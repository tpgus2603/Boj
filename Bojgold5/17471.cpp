#include<bits/stdc++.h>

using namespace std;
vector<int>adj[11];
int human[11];
int total;
int n;
int ans=1e9;

void func(int k ) //nCk 수행 
{
  vector<int> mask(n,1);
  for(int i=0;i<k;i++)
    mask[i]=0;
  do
  {
    vector<int> a;
    vector<int> b;
    int cost=0;
    for(int i=0;i<n;i++)
    {
      if(mask[i]==0)
      {
        a.push_back(i+1);
        cost+=human[i+1];
      }
      if(mask[i]==1)
        b.push_back(i+1);
    }
    queue<int> q;
    bool vis[11];fill(vis,vis+n+1,false);
    for(int i=0;i<b.size();i++)
      vis[b[i]]=true;
    q.push(a[0]);
    vis[a[0]]=true;
    while(!q.empty())
    {
      auto cur=q.front();
      q.pop();
      for(auto next:adj[cur])
      {
        if(vis[next])continue;
        vis[next]=true;
        q.push(next);
      }
    }
    bool flag=true;
    for(auto t:a)
    {
      if(!vis[t])
      {
        flag=false;
        break;
      }
    }
    if(!flag)continue;
    fill(vis,vis+n+1,false);
    for(int i=0;i<a.size();i++)
      vis[a[i]]=true;
    q.push(b[0]);
    vis[b[0]]=true;
    while(!q.empty())
    {
      auto cur=q.front();
      q.pop();
      for(auto next:adj[cur])
      {
        if(vis[next])continue;
        vis[next]=true;
        q.push(next);
      }
    }
    flag=true;
    for(auto t:b)
    {
      if(!vis[t])
      {
        flag=false;
        break;
      }
    }
    if(!flag)continue;
    int minn=abs(total-cost*2);
    ans=min(ans,minn);
  } while (next_permutation(mask.begin(),mask.end()));
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
      cin>>human[i];
      total+=human[i];
  }
  for(int i=1;i<=n;i++)
  {
    int t,temp;
    cin>>t;
    for(int j=0;j<t;j++)
    {
      cin>>temp;
      adj[i].push_back(temp);
      adj[temp].push_back(i);
    }
  }
  for(int i=1;i<=n/2;i++)
    func(i);
  if(ans==1e9)cout<<-1;
  else cout<<ans;
}