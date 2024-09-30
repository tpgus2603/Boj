#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;
int arr[20][20];
int dice[6]; //0이 윗면 5가 아랫면 
int n,m;
int x,y;

void copy()
{
  if(arr[x][y]==0)
    arr[x][y]=dice[5];
  else
  {
    dice[5]=arr[x][y];
    arr[x][y]=0;
  }
}
void east()
{
  y++;
  if(y>=m)
  {
    y--;
    return;
  }
  swap(dice[5],dice[3]);
  swap(dice[5],dice[0]);
  swap(dice[5],dice[2]);
  cout<<dice[0]<<'\n';
  copy();

}
void west()
{
  y--;
  if(y<0)
  {
    y++;
    return;
  }
  swap(dice[5],dice[2]);
  swap(dice[5],dice[0]);
  swap(dice[5],dice[3]);
  cout<<dice[0]<<'\n';
  copy();
}
void north()
{
  x--;
  if(x<0)
  {
    x++;
    return;
  }
  swap(dice[5],dice[4]);
  swap(dice[5],dice[0]);
  swap(dice[5],dice[1]);
  cout<<dice[0]<<'\n';
  copy();
}
void south()
{
  x++;
  if(x>=n){
    x--;
    return;
  }
  swap(dice[5],dice[1]);
  swap(dice[5],dice[0]);
  swap(dice[5],dice[4]);
  cout<<dice[0]<<'\n';
  copy();
}
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int k;
  cin>>n>>m>>x>>y>>k;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>arr[i][j];
  vector<int> order;
  int temp;
  for(int i=0;i<k;i++)
  {
    cin>>temp;
    order.push_back(temp);
  }
  for(int i=0;i<k;i++)
  {
    int t=order[i];
    // cout<<"t: "<<t<<'\n';
    // cout<<"x,y: "<<x<<' '<<y<<'\n';
    switch (t)
    {
    case 1://동쪽
      east();
      break;
    case 2://
      west();
      break;
    case 3://북쪽
      north();
      break;
    case 4:
      south();
    }
  }




}