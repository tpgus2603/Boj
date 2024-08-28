#include<set>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,d,k,c;
  cin>>n>>d>>k>>c;
  vector<int> arr;
  int temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    arr.push_back(temp);
  }
  int maxn=0;
  map<int,int> m;
  for(int i=0;i<k;i++)
  {
    m[arr[i]]++;
  }
  for(int i=0;i<n;i++)
  {
    int cur;
      if(i+k-1>=n)
        cur=i+k-1-n;
      else
        cur=i+k-1;
    //cout<<"cur: "<<cur<<'\n';
    if(i!=0)
    {
      m[arr[i-1]]--;
      if(m[arr[i-1]]==0)
        m.erase(arr[i-1]);
      m[arr[cur]]++;
    }
    int cnt=m.size();
    if(m.find(c)==m.end())
      cnt++;
    //cout<<cnt<<'\n';
    maxn=max(maxn,cnt);
  }
  cout<<maxn;



}