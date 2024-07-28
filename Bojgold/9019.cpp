#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<string>
#include<queue>

#define N first
#define S second
using namespace std; 
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    queue<pair<int,string>> q;
    bool vis[10001];
    fill(vis,vis+10001,false);
    int a,b;
    cin>>a>>b;
    q.push({a,""});
    vis[a]=true;
    bool flag=false;
    while(!q.empty()&&!flag)
    {
      auto cur=q.front();
      q.pop();
      int n1,n2,n3,n4;
       n1=cur.N/1000;
       n2=(cur.N/100)%10;
       n3=(cur.N/10)%10;
       n4=cur.N%10;
      for(int i=0;i<4;i++)
      {
        int next=0;
        string str;
        if(i==0)//D
        {
          next=(cur.N*2)%10000;
          str="D";
        }
        else if(i==1)//S
        {
          if(cur.N==0)
            next=9999;
          else
            next=cur.N-1;
          str="S";
        }
        else if(i==2)//L
        {
          next=n2*1000+n3*100+n4*10+n1;
          str="L";
        }
        else //R
        {
          next=n4*1000+n1*100+n2*10+n3;
          str="R";
        } 
        if(vis[next])continue;
        vis[next]=true;
        if(next==b)
        {
          cout<<cur.S+str<<'\n';
          flag=true;
          break;
        }
        q.push({next,cur.S+str});
      }
    }
  }

}