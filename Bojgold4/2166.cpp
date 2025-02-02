#include <bits/stdc++.h>
#define ld long double
#define ll long long 
#define X first
#define Y second
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<ll, ll>> point(n);
  for (int i = 0; i < n; i++)
    cin >> point[i].X >> point[i].Y;
  ll sum = 0;
  for (int i = 0; i < n; i++)
  {
    int j = (i + 1) % n;
    sum += (point[i].X * point[j].Y) - (point[i].Y * point[j].X);
  }
  ld ans = (ld)abs(sum) / 2.0;
  cout << fixed << setprecision(1) << ans;
}