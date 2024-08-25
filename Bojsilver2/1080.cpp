#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

vector<string>arr;
vector<string>ans;
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin>>n>>m;
  string temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    arr.push_back(temp);
  }
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    ans.push_back(temp);
  }
  int cnt=0;
  if (n >= 3 && m >= 3)
  {
    for (int i = 0; i < n - 2; i++)
    {
      for (int j = 0; j < m - 2; j++)
      {
        if (arr[i][j] != ans[i][j]) // ¹Ù²ãÁÖ±â
        {
          for (int r = i; r <= i + 2; r++)
          {
            for (int c = j; c <= j + 2; c++)
            {
              if (arr[r][c] == '0')
                arr[r][c] = '1';
              else
                arr[r][c] = '0';
            }
          }
          cnt++;
        }
      }
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(arr[i][j]!=ans[i][j])
      {
        cout<<-1;
        return 0;
      }
    }
  }
  cout<<cnt;



}