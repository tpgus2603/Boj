#include<iostream>
#include<vector>
#include<utility>
#include<math.h>
#include<algorithm>

#define X first
#define Y second
using namespace std;

int arr[10001];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  arr[1]++;
  for(int i=2;i<500;i++)
  {
    for(int j=i;i*j<=10000;j++)
    {
      arr[i*j]++;
    }
  }
  int t;
  cin>>t;
  int n;
  while(t--)
  {
    cin>>n;
    vector<pair<int,pair<int,int>>> ans;
    for(int i=2;i<=n;i++)
    {
      if(arr[i]==0&&arr[n-i]==0)
      {
        ans.push_back({abs(n-2*i),{i,n-i}});
      }
    }
    sort(ans.begin(),ans.end());
    auto cur=ans[0];
    if(cur.Y.X>cur.Y.Y)
    {
      cout<<cur.Y.Y<<' '<<cur.Y.X<<'\n';
    }
    else
      cout<<cur.Y.X<<' '<<cur.Y.Y<<'\n';
  }


}