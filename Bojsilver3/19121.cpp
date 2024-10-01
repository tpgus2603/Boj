#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dp(n);  // dp[i] : i번째 수를 마지막으로 하는 연속합의 최대값
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // 로직
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    }

    // 출력
    cout << *max_element(dp.begin(), dp.end()) << '\n';

  
}

