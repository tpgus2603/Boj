#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
    map<int, int> mp; // ≈Î«’¿˚¿∏∑Œ ¿÷¥¬ ¿Ã¡ﬂ»¸
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
      char temp;
      int num;
      cin >> temp >> num;
      if (temp == 'I')
      {
        min_heap.push(num);
        max_heap.push(num);
        mp[num]++;
      }
      else
      {
        if (num == 1) // √÷¥Î»¸ø°º≠ ≤®≥ø
        {
          if (!max_heap.empty())
          {
            while (!mp.empty())
            {
              if (mp.find(max_heap.top()) != mp.end())
              {
                mp[max_heap.top()]--;
                if (mp[max_heap.top()] == 0)
                  mp.erase(max_heap.top());
                max_heap.pop();
                break;
              }
              max_heap.pop();
            }
          }
        }
        else
        {
          if (!min_heap.empty())
          {
            while (!mp.empty())
            {
              if (mp.find(min_heap.top()) != mp.end())
              {
                mp[min_heap.top()]--;
                if (mp[min_heap.top()] == 0)
                {
                  mp.erase(min_heap.top());
                }
                min_heap.pop();
                break;
              }
              min_heap.pop();
            }
          }
        }
      }
    }
    if (mp.empty())
      cout << "EMPTY" << '\n';
    else
    {
      vector<int> arr;
      for (auto temp : mp)
      {
        arr.push_back(temp.first);
      }
      int ma = *max_element(arr.begin(), arr.end());
      int mi = *min_element(arr.begin(), arr.end());
      cout << ma << ' ' << mi << '\n';
    }
  }
}