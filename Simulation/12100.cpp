#include <iostream>
#include <algorithm>

using namespace std;

int arr[21][21];
bool flag[21][21];
int n;
int ans;
enum
{
  up,
  le,
  ri,
  down
};
int num = 0;
void func(int cnt, int dir)
{
  if (cnt > 0)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        flag[i][j] = false;
      }
    }
    switch (dir)
    {
    case up:
      for (int i = 1; i <= n; i++)
      {
        for (int j = 1; j <= n; j++)
        {
          int x = i;
          int y = j;
          while (1)
          {
            int dx = x - 1;
            if (dx <= 0)
              break;
            if (arr[dx][y] == 0)
            {
              arr[dx][y] = arr[x][y];
              arr[x][y] = 0;
              x = dx;
            }
            else if (!flag[dx][y] && arr[dx][y] == arr[x][y])
            {
              arr[dx][y] = 2 * arr[x][y];
              arr[x][y] = 0;
              flag[dx][y] = true;
              break;
            }
            else
              break;
          }
        }
      }
      break;
    case le:
      for (int i = 1; i <= n; i++)
      {
        for (int j = 1; j <= n; j++)
        {
          int x = i;
          int y = j;
          while (1)
          {
            int dy = y - 1;
            if (dy <= 0)
              break;
            if (arr[x][dy] == 0)
            {
              arr[x][dy] = arr[x][y]; 
              arr[x][y] = 0;
              y = dy;
            }
            else if (!flag[x][dy] && arr[x][dy] == arr[x][y])
            {
              arr[x][dy] = 2 * arr[x][y];
              arr[x][y] = 0;
              flag[x][dy] = true;
              break;
            }
            else
              break;
          }
        }
      }
      break;
    case ri:
      for (int i = 1; i <=n; i++)
      {
        for (int j = n; j > 0; j--)
        {
          int x = i;
          int y = j;
          while (1)
          {
            int dy = y + 1;
            if (dy > n)
              break;
            if (arr[x][dy] == 0)
            {
              arr[x][dy] = arr[x][y];
              arr[x][y] = 0;
              y = dy;
            }
            else if (!flag[x][dy] && arr[x][dy] == arr[x][y])
            {
              arr[x][dy] = 2 * arr[x][y];
              arr[x][y] = 0;
              flag[x][dy] = true;
              break;
            }
            else
              break;
          }
        }
      }
      break;
    case down:
      for (int i = n; i > 0; i--)
      {
        for (int j = 1; j <=n; j++)
        {
          int x = i;
          int y = j;
          while (1)
          {
            int dx = x + 1;
            if (dx > n)
              break;
            if (arr[dx][y] == 0)
            {
              arr[dx][y] = arr[x][y];
              arr[x][y] = 0;
              x = dx;
            }
            else if (!flag[dx][y] && arr[dx][y] == arr[x][y])
            {
              arr[dx][y] = 2 * arr[x][y];
              arr[x][y] = 0;
              flag[dx][y] = true;
              break;
            }
            else
              break;
          }
        }
      }
    }
  }

  if (cnt == 5)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
        ans = max(ans, arr[i][j]);
    }
    num++;
    return;
  }
  for (int dk = 0; dk < 4; dk++)
  {
    int back[21][21];
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        back[i][j] = arr[i][j];
      }
    }
    func(cnt + 1, dk);
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        arr[i][j] = back[i][j];
      }
    }
  }
  
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
      cin >> arr[i][j];
  }
  func(0, up);
  cout << ans << '\n';
  return 0;
}