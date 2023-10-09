#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int temp;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 값과 부호를 나타내는 수를 집어넣음 음수면 0 양수면 1
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    if (temp < 0) // 음수인경우 확인기호 0 넣음
    {
      pq.push({temp * (-1), 0});
    }
    else if (temp > 0)
    {
      pq.push({temp, 1});
    }
    else // 0이 들어온경우 출력
    {
      if (!pq.empty())
      {
        auto k = pq.top();
        pq.pop();
        if (!k.second) // 음수인경우
          cout << k.first * (-1) << '\n';
        else
          cout << k.first << '\n';
      }
      else
        cout<<'0'<<'\n';
    }
  }
}