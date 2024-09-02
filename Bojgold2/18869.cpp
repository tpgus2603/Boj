#include<iostream>
#include<vector>
#include<algorithm>
int arr[100][10000];
using namespace std;


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m,n;
  cin>>m>>n;
  for(int i=0;i<m;i++)
  {
    vector<int> temp;
    for(int j=0;j<n;j++)
    {
      cin>>arr[i][j];
      temp.push_back(arr[i][j]);
    }
    sort(temp.begin(),temp.end());
    temp.erase(unique(temp.begin(),temp.end()),temp.end());//중복제거 
    for(int j=0;j<n;j++)
      arr[i][j]=lower_bound(temp.begin(),temp.end(),arr[i][j])-temp.begin();
  }

  int cnt=0;
  for(int i=0;i<m-1;i++)
  {
    for(int j=i+1;j<m;j++)
    {
      bool flag=true;
      for(int k=0;k<n;k++)
      {
        if(arr[i][k]!=arr[j][k])
        {
          flag=false;
          break;
        }
      }
      if(flag)
      {
        cnt++;
        //cout<<i<<' '<<j<<'\n';
      }
    }
  }
  cout<<cnt;
}
