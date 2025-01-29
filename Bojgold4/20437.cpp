#include<bits/stdc++.h>

using namespace std;

int arr[26][10001]; //i번째 문자까지 특정 알파벳의 개수 

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);

  int t;
  cin>>t;
  while(t--)
  {
    string w;
    int k;
    cin>>w>>k;
    vector<vector<int>> arr(26);
    int len=w.length();
    for(int i=0;i<len;i++)
    {
      arr[w[i]-'a'].push_back(i);
    }
    int minn=1e9;
    int maxn=0;
    for(int cur=0;cur<26;cur++)
    {
      int t=arr[cur].size();
      for(int j=k-1;j<t;j++)
      {
        minn=min(arr[cur][j]-arr[cur][j-k+1]+1,minn);
        maxn=max(arr[cur][j]-arr[cur][j-k+1]+1,maxn);
      }
    }
    if(maxn==0)
      cout<<-1<<'\n';
    else
      cout<<minn<<' '<<maxn<<'\n';
  }

}