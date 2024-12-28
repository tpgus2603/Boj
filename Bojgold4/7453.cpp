#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  vector<int>A,B,C,D;
  int n;
  cin>>n;
  int a,b,c,d;
  for(int i=0;i<n;i++)
  {
    cin>>a>>b>>c>>d;
    A.push_back(a);B.push_back(b);C.push_back(c);D.push_back(d);
  }
  vector<int>AB;
  vector<int>CD;
  for(auto a:A)
  {
    for(auto b:B)
    {
      int sum=a+b;
      AB.push_back(sum);
    }
  }
  for(auto c:C)
  {
    for(auto d:D)
    {
      int sum=c+d;
      CD.push_back(sum);
    }
  }
  sort(AB.begin(),AB.end());
  sort(CD.begin(),CD.end());
  int size=AB.size();
  long long cnt=0;
  for(int i=0;i<size;i++)
  {
    cnt+=upper_bound(CD.begin(),CD.end(),-AB[i])-lower_bound(CD.begin(),CD.end(),-AB[i]);
  }
  cout<<cnt;

}