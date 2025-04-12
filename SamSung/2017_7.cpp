#include<bits/stdc++.h>

using namespace std;
int dir[4]; //-1이면 반시계 1이면 시계 0이면 회전안함 
vector<int> table[4];

void func(int n, int d)
{
  dir[n-1]=d;
  for(int i=n-1;i<3;i++) //양의방향
  {
    if(table[i][2]!=table[i+1][6]) //다른경우
      dir[i+1]=-1*dir[i]; //반대로 회전
    else 
      dir[i+1]=0;
  }
  for(int i=n-1;i>0;i--)
  {
    if(table[i][6]!=table[i-1][2])
      dir[i-1]=-1*dir[i];
    else 
      dir[i-1]=0;
  }
}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int k;
  for(int i=0;i<4;i++)
  {
    string t;
    cin>>t;
    for(int j=0;j<8;j++)
    {
      table[i].push_back(t[j]-'0');
    }
  }
  cin>>k;
  int n,d;
  while(k--)
  {
    cin>>n>>d;
    func(n,d); //방향결정 
    for(int i=0;i<4;i++) //각 테이블 회전
    {
      if(dir[i]==-1) //반시계
        rotate(table[i].begin(),table[i].begin()+1,table[i].end());
      else if(dir[i]==1)//시계계
        rotate(table[i].begin(),table[i].end()-1,table[i].end());
    }
  }
  int ans=0;
  for(int i=0;i<4;i++)
  {
    int t=table[i][0]; //t=1이면 남쪽지방
    ans+=t*(int)pow(2,i);
  }
  cout<<ans;

}