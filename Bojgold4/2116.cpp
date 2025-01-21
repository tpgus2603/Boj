#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dice[10000][6];

//0,5 1,3 2,4 가 쌍을 이룸  down면과 대칭인 면 제외하고 최대값 구함 

//대칭인 면 구하기
int func(int k)
{
  switch (k)
  {
  case 0:
    return 5;
  case 1:
    return 3;
  case 2:
    return 4;
  case 3:
    return 1;
  case 4:
    return 2;
  case 5:
    return 0;
    break;
  }
}

int findmax(int idx,int up,int down)
{
  int ans=0;
  for(int i=0;i<6;i++)
  {
    if(i==up||i==down)continue;
    ans=max(ans,dice[idx][i]);
  }
  return ans;
}


int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<6;j++)
      cin>>dice[i][j];
  }
  int ans=0;
  //0,5 1,3 2,4 가 쌍을 이룸 
  for(int cur=0;cur<6;cur++)
  {
    int sum=0;
    int up=cur;
    //int temp=dice[0][up];
    int down=func(up);
    sum+=findmax(0,up,down);
    //cout<<sum<<'\n';
    for(int i=1;i<n;i++)
    {
      for(int j=0;j<6;j++)
      {
        if(dice[i][j]==dice[i-1][up])
          down=j;
      }
      up=func(down);
      sum+=findmax(i,up,down);
    }
    ans=max(sum,ans);
  }
  cout<<ans;


}