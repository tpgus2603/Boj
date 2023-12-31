#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int l, m;
vector<char> arr2;
vector<char> arr;
void func(int cur)
{
  if (cur == l)
  {
    int cnt = 0;
    for (auto k : arr2)
    {
      if (k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u')
        cnt++;
    }
     if (cnt >= 1 && l - cnt >= 2)
     {
      for (auto k : arr2)
        cout << k ;
      cout << '\n';
     }
    return;
  }
  for (int i = 0; i < m; i++)
  {
    if (cur == 0)
    {
      arr2.push_back(arr[i]);
    }
    else
    {
      if (arr2[cur - 1] < arr[i])
        arr2.push_back(arr[i]);
      else
        continue;
    }
      func(cur + 1);
      arr2.pop_back();
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> l >> m;
  char temp;
  for (int i = 0; i < m; i++)
  {
    cin >> temp;
    arr.push_back(temp);
  }
  sort(arr.begin(), arr.end());
  func(0);
}