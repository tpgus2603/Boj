#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  set<int> card;
  int n;
  cin>>n;
  int temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    card.insert(temp);
  }
  int m;
  cin>>m;
  vector<int>judge;
  for(int i=0;i<m;i++)
  {
    cin>>temp;
    judge.push_back(temp);
  }
  for(auto k:judge)
  {
    if(card.count(k)>0)
      cout<<1<<' ';
    else
      cout<<0<<' ';
  }



}