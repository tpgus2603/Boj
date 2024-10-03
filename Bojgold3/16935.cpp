#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<vector<int>> arr;
int n,m,r;

void rotate1()
{
  int num=n/2;
  for(int i=0;i<num;i++)
  {
    swap(arr[i],arr[n-i-1]);
  } 
}
void rotate2()
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m/2;j++)
    {
      swap(arr[i][j],arr[i][m-j-1]);
    }
  }
}

void rotate3() //arr크기만큼 회전 
{
  int r=arr.size();
  int c=arr[0].size();
  n=c;
  m=r;
  vector<vector<int>> element(c,vector<int>(r,0));
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      element[j][r-i-1]=arr[i][j];
    }
  }
  arr=element;
}
void rotate4()
{
  int r=arr.size();
  int c=arr[0].size();
  n=c;
  m=r;
  vector<vector<int>> element(c,vector<int>(r,0));
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      element[j][i]=arr[i][c-j-1];
    }
  }
  arr=element;
}
void rotate5()
{
  vector<vector<int>> element(n,vector<int>(m,0));
  for(int i=0;i<n/2;i++)
  {
    for(int j=m/2;j<m;j++)
    {
      element[i][j]=arr[i][j-m/2];
    }
  }
  for(int i=n/2;i<n;i++)
  {
    for(int j=m/2;j<m;j++)
    {
      element[i][j]=arr[i-n/2][j];
    }
  }
  for(int i=n/2;i<n;i++)
  {
    for(int j=0;j<m/2;j++)
    {
      element[i][j]=arr[i][j+m/2];
    }
  }
  for(int i=0;i<n/2;i++)
  {
    for(int j=0;j<m/2;j++)
    {
      element[i][j]=arr[i+n/2][j];
    }
  }
  arr=element;
}
void rotate6()
{
  vector<vector<int>> element(n,vector<int>(m,0));
  for(int i=0;i<n/2;i++)
  {
    for(int j=m/2;j<m;j++)
    {
      element[i][j]=arr[i+n/2][j];
    }
  }
  for(int i=n/2;i<n;i++)
  {
    for(int j=m/2;j<m;j++)
    {
      element[i][j]=arr[i][j-m/2];
    }
  }
  for(int i=n/2;i<n;i++)
  {
    for(int j=0;j<m/2;j++)
    {
      element[i][j]=arr[i-n/2][j];
    }
  }
  for(int i=0;i<n/2;i++)
  {
    for(int j=0;j<m/2;j++)
    {
      element[i][j]=arr[i][j+m/2];
    }
  }
  arr=element;

}


int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int temp;
  cin>>n>>m>>r;
  for(int i=0;i<n;i++)
  {
    vector<int> t;
    for(int j=0;j<m;j++)
    {
      cin>>temp;
      t.push_back(temp);
    }
    arr.push_back(t);
  }
  vector<int> opt;
  
  for(int i=0;i<r;i++)
  {
    cin>>temp;
    opt.push_back(temp);
  }
  for(auto temp:opt)
  {
    switch (temp)
    {
    case 1:
      rotate1();
      break;
    case 2:
      rotate2();
      break;
    case 3:
      rotate3();
      break;
    case 4:
      rotate4();
      break;    
    case 5:
      rotate5();
      break;  
    case 6:
      rotate6();
      break;
    }
  }
  int r=arr.size();
  int c=arr[0].size();
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
      cout<<arr[i][j]<<' ';
    cout<<'\n';
  }



}