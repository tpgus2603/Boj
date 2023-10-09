#include <iostream>
#include <vector>
#include <queue>

#define ll long long
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  priority_queue<ll, vector<ll>, greater<ll>> pq; // 최소 힙
  int temp;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    pq.push(temp);
  }
  ll result=0;
  int pqn = pq.size();
  
    while (--pqn) // heap에 1개 남을 때 까지
    {
      ll n1 = pq.top();
      pq.pop();
      ll n2 = pq.top();
      pq.pop();
      pq.push(n1 + n2);
      result += (n1 + n2);
    }
    cout << result;
  
}