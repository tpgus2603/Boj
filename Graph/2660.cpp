#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<int> adj[51];
int dis[51];
int score[51];
int main()
{
  int n;
  cin>>n;
  while(1)
  { 
    int a,b;
    cin>>a>>b;
    if(a==-1&&b==-1)
      break;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }


  for(int i=1;i<=n;i++)
    {
      queue<int> q;
      fill(dis+1,dis+n+1,-1);
      dis[i]=0;
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
      if(*min_element(dis+1,dis+n+1)==-1)
        score[i]=1000;
      else
        score[i]=*max_element(dis+1,dis+n+1);
    }
  int cnt=0;
  int min_score=*min_element(score+1,score+n+1);
  vector<int>min_arr;
  for(int i=1;i<=n;i++)
  {
    if(score[i]==min_score&&score[i]!=1000)
      min_arr.push_back(i);
  }
  cout<<min_score<<' '<<min_arr.size()<<'\n';
  for(auto k:min_arr)
    cout<<k<<' ';
}



// void dfs(int a, int b)
// {
//   for(auto nxt: adj[b])
//   { 
//     if(!dis[a][nxt])
//     {
//         dis[a][nxt]=dis[a][b]+1;
//         dfs(a,nxt);
//     }
//   }
// }

  // for(int i=1;i<=n;i++)
  //   {
  //     for(auto nxt:adj[i])
  //     {
  //       dis[i][nxt]=1;
  //       dfs(i,nxt);
  //     }
  //     for(auto nxt:adj[i])
  //       dis[i][nxt]=1;
  //   }