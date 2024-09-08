#include<algorithm>
#include<iostream>
#include<utility>
#include<queue>
#include<cmath>

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

#define X first  
#define Y second
using namespace std;

bool vis[101];
pair<int,int> arr[101]; //편의점 1~100 
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    fill(vis,vis+n+1,false);
    for(int i=0;i<=n;i++)
    {
      arr[i].X=0;
      arr[i].Y=0;
    }
    pair<int,int> st;
    cin>>arr[0].X>>arr[0].Y; //0이 출발점 
    for(int i=1;i<=n;i++)  //편의점 
    {
      cin>>arr[i].X>>arr[i].Y;
    }
    pair<int,int> goal;
    cin>>goal.X>>goal.Y;
    queue<int> q;
    q.push(0);
    vis[0]=true;
    bool ans=false;
    while(!q.empty())
    {
      int cur=q.front();
      q.pop();
      int dif=abs(arr[cur].X-goal.X)+abs(arr[cur].Y-goal.Y);
      if(dif<1050)
      {
        ans=true;
        break;
      }
      for(int i=1;i<=n;i++)
      {
        if(vis[i])continue;
        int temp=abs(arr[cur].X-arr[i].X)+abs(arr[cur].Y-arr[i].Y);
        if(temp>=1050)continue;
        vis[i]=true;
        q.push(i);
      }
    }
    if(ans)
      cout<<"happy"<<'\n';
    else
      cout<<"sad"<<'\n';
  }

}

