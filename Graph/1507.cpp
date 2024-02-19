#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int d[21][21];
int arr[21][21];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cin>>d[i][j];
      arr[i][j]=d[i][j];
    }
  }
  bool ok=true;
  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if(i!=k&&j!=k&&d[i][j]==d[i][k]+d[k][j])
          arr[i][j]=0;
        else if(d[i][j]>d[i][k]+d[k][j])
          ok=false;
      }
    }
  }
  int sum=0;
  if (ok)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j < i; j++)
      {
        sum+=arr[i][j];
      }
    }
    cout<<sum;
  }
  else
    cout << -1;
}