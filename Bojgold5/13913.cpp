#include<bits/stdc++.h>

using namespace std;

bool vis[200001];
int pre[200001];
int n,k;
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  queue<int> q;
  q.push(n);
  vis[n]=true;
  while(!q.empty())
  {
    auto cur=q.front();
    q.pop();
    //cout<<cur<<' ';
    if(cur==k)
    {
      break;
    }
    if((cur-1>=0)&&!vis[cur-1])
    {
      q.push(cur-1);
      vis[cur-1]=true;
      pre[cur-1]=cur;
    }
    if(cur+1<100000&&!vis[cur+1])
    {
      q.push(cur+1);
      vis[cur+1]=true;
      pre[cur+1]=cur;
    }
    if(2*cur<200000&&!vis[2*cur])
    {
      q.push(2*cur);
      vis[2*cur]=true;
      pre[2*cur]=cur;
    }
  }
  vector<int>path;
  path.push_back(k);
  int cur=k;
  while(cur!=n)
  {
    path.push_back(pre[cur]);
    cur=pre[cur];
  }
  reverse(path.begin(),path.end());
  cout<<path.size()-1<<'\n';
  for(auto k: path)
  {
    cout<<k<<' ';
  }

}