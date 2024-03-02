#include<iostream>
#include<vector>

using namespace std;

int n;
long long b;
vector<vector<int>> arr;
vector<vector<int>> pmatrix(vector<vector<int>> & matrix, long long pow)
{
  if(pow<=1)
    return matrix;
  if(pow%2==0) //
  {
    vector<vector<int>> temp= pmatrix(matrix,pow/2);
    vector<vector<int>> temp2(n,vector<int>(n,0));
    for(int i=0;i<n;i++) //i행
    {
      for(int j=0;j<n;j++) //j열
      {
        int res=0;
        for(int k=0;k<n;k++) //
        {
          res+=(temp[i][k]*temp[k][j]);
        }
        temp2[i][j]=res%1000;
      }
    }
    return temp2;
  }
  else
  {
    vector<vector<int>> temp= pmatrix(matrix,pow/2);
    vector<vector<int>> temp2(n,vector<int>(n,0));
    for(int i=0;i<n;i++) //i행
    {
      for(int j=0;j<n;j++) //j열
      {
        int res=0;
        for(int k=0;k<n;k++) //
        {
          res+=(temp[i][k]*temp[k][j]);
        }
        temp2[i][j]=res%1000;
      }
    }
    vector<vector<int>> temp3(n,vector<int>(n,0));
    for(int i=0;i<n;i++) //i행
    {
      for(int j=0;j<n;j++) //j열
      {
        int res=0;
        for(int k=0;k<n;k++) //
        {
          res+=(temp2[i][k]*matrix[k][j]);
        }
        temp3[i][j]=res%1000;
      }
    }
    return temp3;
  }

}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n>>b;
  for(int i=0;i<n;i++)
  {
    vector<int> temp;
    for(int j=0;j<n;j++)
    {
      int t;
      cin>>t;
      temp.push_back(t);
    }
    arr.push_back(temp);
  }
  
  vector<vector<int>> ans=pmatrix(arr,b);

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
      cout<<ans[i][j]%1000<<' ';
    cout<<'\n';
  }


}