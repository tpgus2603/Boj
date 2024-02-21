#include<iostream>
#include<algorithm>
#include<string>


using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int maxn=1;
int arr[20][20];
bool isused[100];

int r,c;

void func(int x, int y,int cnt)
{

  for(int i=0;i<4;i++)
  {
    int row=x+dx[i];
    int col=y+dy[i];
    if(row<0||row>=r||col<0||col>=c)continue;
    if(isused[arr[row][col]]) continue;
    isused[arr[row][col]]=true;
    cnt++;
    if(cnt>maxn)
      maxn=cnt;
    func(row,col,cnt);
    isused[arr[row][col]]=false;
    cnt--;
  }

}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>r>>c;
  string temp;
  for(int i=0;i<r;i++)
  {
    cin>>temp;
    for(int j=0;j<c;j++)
    {
      arr[i][j]=temp[j]-'0';
    }
  }
  fill(isused, isused + 100, 0);
  isused[arr[0][0]] = true;
  func(0, 0, 1);
  cout<<maxn;



}