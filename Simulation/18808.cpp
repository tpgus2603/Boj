#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

#define X first
#define Y second
using namespace std;
int n,m,k;
int board[41][41];
vector<vector<int>> rotate(vector<vector<int>> &arr,int r, int c)//90도 회전함수 
{
  vector<vector<int>> turn;
  for(int i=0;i<c;i++)
  {
    vector<int>temp;
    for(int j=r-1;j>=0;j--)
      temp.push_back(arr[j][i]);
    turn.push_back(temp);
  }
  return turn;
}

bool find(vector<vector<int>>& temp,int r,int c)
{
  bool isok = true;
  bool flag = false;
  for (int j = 0; j <=n - r; j++) // 0도에서 찾기
  {
    for (int k = 0; k<=m - c; k++)
    {
      pair<int, int> st = {j, k}; // 시작점
      isok = true;
      for (int x = st.X; x < st.X + r; x++)
      {
        for (int y = st.Y; y < st.Y + c; y++)
        {
          if (board[x][y] == 1 && temp[x-st.X][y-st.Y] == 1)
          {
            isok = false;
            break;
          }
        }
      }
      if (isok)
      {
        for (int x = st.X; x < st.X + r; x++)
        {
          for (int y = st.Y; y < st.Y + c; y++)
          {
            if(board[x][y]==0&&temp[x-st.X][y-st.Y]==1)
              board[x][y] = 1;
          }
        }
        flag = true;
        break;
      }
    }
    if (flag)
      break;
  }
    if(!flag) isok=false;
  return isok;
}

int main()
{
  vector<vector<int>> stickers[101]; //(1~k까지 스티커들 )
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  int idx = 1;
  int t=k;
  while (t--) // 스티커 입력
  {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> sticker;
    for (int i = 0; i < r; i++)
    {
      vector<int> temp;
      int a;
      for (int j = 0; j < c; j++)
      {
        cin >> a;
        temp.push_back(a);
      }
      sticker.push_back(temp);
    }
    stickers[idx++] = sticker;
  }
  for (int i = 1; i <= k; i++)
  {
    vector<vector<int>> temp = stickers[i];
    int r = temp.size();
    int c = temp[0].size();
    bool isok = true;
    isok = find(temp, r, c);
    if (!isok) // 90도 회전시켜서 해보기
    {
      temp = rotate(temp, r, c);
      swap(r, c);
      isok = find(temp, r, c);
    }
    if (!isok) // 180도 회전시켜서 해보기
    {
      temp = rotate(temp, r, c);
      swap(r, c);
      isok = find(temp, r, c);
    }
    if (!isok) // 270도 회전시켜서 해보기
    {
      temp = rotate(temp, r, c);
      swap(r, c);
      isok = find(temp, r, c);
    }
  }


  int cnt=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(board[i][j]==1)
        cnt++;
    }
  }
  cout<<cnt;
}