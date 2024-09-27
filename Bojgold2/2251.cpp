#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>
#include<string>
#define X first
#define Y second

using namespace std;

set<int> ans;
bool vis[201][201][201];//A,B,C
int lim[3];
pair<int,int> move(int from,int to,int n1,int n2) //from->to로 물 부음 현재 물량n1,n2
{
  int gap=lim[to]-n2;
  int amount=min(n1,gap);
  return {n1-amount,n2+amount}; //from물양 ,to물양 반환 
}

void dfs(int a,int b,int c)
{
  if(vis[a][b][c])
    return;
  vis[a][b][c]=true;
  if(a==0)
  { 
     ans.insert(c);
  }
  //a->b
  {
    auto temp=move(0,1,a,b); //a,b물양 반환 
    dfs(temp.first,temp.second,c);
  }
  //a->c
  {
    auto temp=move(0,2,a,c); //a,b물양 반환 
    dfs(temp.first,b,temp.second);
  }
  //b->a
  {
    auto temp=move(1,0,b,a); //a,b물양 반환 
    dfs(temp.second,temp.first,c);
  }

  //b->c
  {
    auto temp=move(1,2,b,c); //a,b물양 반환 
    dfs(a,temp.first,temp.second);
  }
  //c->a
  {
    auto temp=move(2,0,c,a); //a,b물양 반환 
    dfs(temp.second,b,temp.first);
  }
  //c->b
  {
    auto temp=move(2,1,c,b);
    dfs(a,temp.second,temp.first);
  }

}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>lim[0]>>lim[1]>>lim[2];
  dfs(0,0,lim[2]);
  for(auto temp:ans)
  {
    cout<<temp<<' ';
  }
}