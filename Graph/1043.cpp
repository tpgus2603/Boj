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
    cin>>temp;
    party[i].push_back(temp);
    while(--num)
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
//연결리스트 만드는 방법 
//     int prv, nxt;
//     cin >> prv;
//     pt[i].push_back(prv);

//     while(--no) {
//       cin >> nxt;
//       pt[i].push_back(nxt);
//       adj[nxt].push_back(prv);
//       adj[prv].push_back(nxt); // 동일한 파티에 참석한 앞뒤 사람끼리 간선이 연결되어있다고 생각
//       swap(prv, nxt);
//     }
//   }