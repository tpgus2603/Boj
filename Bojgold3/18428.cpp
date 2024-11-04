#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

#define X first 
#define Y second 
using namespace std;
short arr[6][6]; //X=0, S=1,T=2,O=3

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  vector<pair<int,int>> teacher;
  for(int i=0;i<n;i++)
  {
    char temp;
    for(int j=0;j<n;j++)
    {
      cin>>temp;
      switch (temp)
      {
      case 'X':
        arr[i][j]=0;
        break;
      case 'S':
        arr[i][j]=1;
        break;
      case 'T':
        arr[i][j]=2;
        teacher.push_back({i,j});
        break;
      default:
        break;
      }
    }
  }
  vector<int> mask(n*n,1);
  for(int i=0;i<3;i++)
    mask[i]=0;
  bool ans=false;
  //  X=0, S=1,T=2,O=3
  do
  {
    //빈칸 아니면 스킵 
    vector<pair<int,int>> object;
    for(int i=0;i<n*n;i++)
    {
     if(mask[i]==0) //
      object.push_back({i/6,i%6});
    }
    bool flag =true;
    for(auto temp: object)
      if(arr[temp.X][temp.Y]!=0) flag=false;
    if(!flag)continue;
    for(auto temp:object)
      arr[temp.X][temp.Y]=3;
    bool ok=true;
    for (auto temp :teacher)
    {
      //좌 
      for (int i = temp.Y - 1; i >= 0; i--)
      {
        if (arr[temp.X][i]==1)ok=false;
        if(arr[temp.X][i]==3)break;
      }
      // 우
      for (int i = temp.Y +1; i<n; i++)
      {
        if (arr[temp.X][i]==1)ok=false;
        if(arr[temp.X][i]==3)break;
      }
      // 상
      for (int i = temp.X -1; i>=0; i--)
      {
        if (arr[i][temp.Y]==1)ok=false;
        if(arr[i][temp.Y]==3)break;
      }
      // 하
      for (int i = temp.X +1; i<n; i++)
      {
        if (arr[i][temp.Y]==1)ok=false;
        if(arr[i][temp.Y]==3)break;
      }
    }

      if(ok==true)
      {
        ans=true;
        break;
      }
    for(auto temp:object)
      arr[temp.X][temp.Y]=0;
  } while (next_permutation(mask.begin(),mask.end()));
  (ans ==true) ? cout<<"YES" :cout<<"NO";

}