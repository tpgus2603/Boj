#include<iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    int a,b;
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
      cin>>a>>b;
    cout<<n-1<<'\n';
  }


}