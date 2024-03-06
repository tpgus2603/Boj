#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a,b;
  cin>>a>>b;
  set<int> s1;
  vector<int> s2;
  int temp;
  for(int i=0;i<a;i++)
  {
	cin>>temp;
    s1.insert(temp);
  }
  for(int i=0;i<b;i++)
  {
    cin>>temp;
    s2.push_back(temp);
  }
  int cross=0;
  for(auto k:s2)
  {
    if(s1.count(k)>0)
      cross++;
  }
  int ans=s1.size()-cross+s2.size()-cross;
  cout<<ans;





}