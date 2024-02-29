#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

#define X first
#define Y second
int arr[51][51];
int mask[13];
using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  vector<pair<int,int>> chick;
  vector<pair<int,int>> home;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cin>>arr[i][j];
      if(arr[i][j]==1)
        home.push_back({i,j});
      else if(arr[i][j]==2)
        chick.push_back({i,j});
    }
  }
  int k=chick.size();
  for(int i=m;i<k;i++)
  {
    mask[i]=1;
  }
  vector<int> dis;
  do
  {
    vector<pair<int,int>> choose; //선택된 m개 좌표들 
    for(int i=0;i<k;i++)
    {
      if(mask[i]==0)
      choose.push_back(chick[i]);
    }
    int dist=0;
    for(int i=0;i<home.size();i++) //집에서  최소 치킨집  구하기 
    {
      int mi=1e9;
      for(int j=0;j<m;j++)
      {
        int temp=abs(home[i].X-choose[j].X)+abs(home[i].Y-choose[j].Y);
        mi=min(mi,temp);
      }
      dist+=mi;
    }
    dis.push_back(dist);

  } while (next_permutation(mask,mask+k));
  int ans=*min_element(dis.begin(),dis.end());
  cout<<ans;

}