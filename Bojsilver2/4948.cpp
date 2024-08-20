#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int arr[250001]; // ¼Ò¼ö =0
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n = -1;
  arr[1] = 1;
  for (int i = 2; i <= 1000; i++) // i*j
  {
    for (int j = i; j * i <=250000; j++)
    {
      arr[i * j]++;
    }
  }
  while(1)
  {
    cin >> n;
    if (n == 0)
      break;
    int cnt = 0;
    for (int i = n + 1; i <=2 * n; i++)
    {
      if (arr[i] == 0)
        cnt++;
    }
    cout << cnt << '\n';
  }
}