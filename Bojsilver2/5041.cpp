#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

int dis[1000001];

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int f,s,g,u,d;
  cin>>f>>s>>g>>u>>d;
  fill(dis,dis+f+1,-1);
  queue<int> q;
  q.push(s);
  dis[s]=0;
  while(!q.empty())
  {
    int cur=q.front();
    q.pop();
    if(cur==g)
      break;
    for(int i=0;i<2;i++)
    {
      int dx=cur;
      if(i==0)
        dx=cur+u;
      else
        dx=cur-d;
      if(dx<0||dx>f)continue;
      if(dis[dx]>=0)continue;
      dis[dx]=dis[cur]+1;
      q.push(dx);
    }
  }
  if(dis[g]>=0)
    cout<<dis[g];
  else
    cout<<"use the stairs";


}