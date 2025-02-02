#include<bits/stdc++.h>

using namespace std;
int pos[1000001]; 
int score[100001];

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  int t;
  for(int i=1;i<=n;i++)
  {
    cin>>t;
    pos[t]=i;
  }
  int maxval=1e6;
  for(int i=1;i<=maxval;i++)
  {
    if(pos[i]==0)continue;
    for(int j=2*i;j<=maxval;j+=i)
    {
      if(pos[j]==0)continue;
      score[pos[i]]++;
      score[pos[j]]--;
    }
  } 
  for(int i=1;i<=n;i++)
    cout<<score[i]<<' ';

}