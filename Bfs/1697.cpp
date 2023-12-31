#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;
int n, k;
bool isclosed[1000001];

int bfs()
{
  queue<pair<int, int>> q;
  q.push({n, 0});
  isclosed[n] = 1;
  while (!q.empty())
  {
    auto cur = q.front();
    if (cur.X == k)
      return cur.Y;
    q.pop();
    if (cur.X-1>=0&&isclosed[cur.X - 1]==0)
    {
      isclosed[cur.X-1]=1;
      q.push({cur.X - 1, cur.Y + 1});
    }
    if (cur.X<k&&isclosed[cur.X + 1]==0)
    {
      isclosed[cur.X+1]=1;
      q.push({cur.X + 1, cur.Y + 1});
    }
    if (cur.X<k&&isclosed[cur.X * 2]==0)
    {
      isclosed[cur.X*2]=1;
      q.push({cur.X * 2, cur.Y + 1});
    }
  }
  return -1;
}

int main()
{
  cin >> n >> k;
  cout << bfs();
}