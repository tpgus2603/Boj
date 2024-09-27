#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

#define X first
#define Y second
using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  vector<pair<int,int>> arr;
  int x,y;
  for(int i=0;i<n;i++)
  {
      cin>>x>>y;
      arr.push_back({x,y});
  }
  sort(arr.begin(),arr.end());
  vector<pair<int,int>> ans;
  ans.push_back(arr[0]);
  for(int i=1;i<n;i++)
  {
    auto temp=ans.back();
    if(temp.Y>=arr[i].X) //겹치는경우
    {
      int st=min(temp.X,arr[i].X);
      int ed=max(temp.Y,arr[i].Y);
      ans.pop_back();
      ans.push_back({st,ed});
    }
    else//안겹치는경우
    {
      ans.push_back(arr[i]);
    }
  }
  int sum=0;
  for(auto temp:ans)
  {
    sum+=temp.Y-temp.X;
    //cout<<temp.X<<' '<<temp.Y<<'\n';
  }
  cout<<sum;
}