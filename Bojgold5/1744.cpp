#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll dp[50][2]; //[0]인경우 안묶 [1]인경우 현재 위치기준 왼쪽과 묶음 
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  vector<ll> arr(n,0);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  sort(arr.begin(),arr.end());
  dp[0][0]=arr[0];dp[0][1]=arr[0];
  for(int i=1;i<n;i++)
  {
    //dp[i][0]
    dp[i][0]=max(dp[i-1][0],dp[i-1][1])+arr[i];
    //dp[i][1]
    dp[i][1]=dp[i-1][0]+arr[i-1]*arr[i]-arr[i-1];
  }
  cout<<max(dp[n-1][0],dp[n-1][1]);

}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> positives, negatives;
    int ones = 0, zeros = 0;
    
    // 입력된 수들을 범주별로 분리한다.
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num > 1)
            positives.push_back(num);  // 2 이상의 양수는 곱셈의 이득이 있음
        else if (num == 1)
            ones++;                    // 1은 그냥 더하는 것이 이득
        else if (num == 0)
            zeros++;                   // 0은 음수를 상쇄하는 역할을 할 수 있음
        else
            negatives.push_back(num);  // 음수는 서로 곱하면 양수가 됨
    }
    
    // 양수는 큰 수부터 곱하는 것이 최대값을 보장한다.
    sort(positives.begin(), positives.end(), greater<int>());
    // 음수는 작은 수부터(즉, 절댓값이 큰 순서) 곱해야 최적이다.
    sort(negatives.begin(), negatives.end());
    
    int result = 0;
    
    // 양수들의 pairing
    for (int i = 0; i < positives.size(); i += 2) {
        if (i + 1 < positives.size())
            result += positives[i] * positives[i + 1];
        else
            result += positives[i];  // 짝이 안 맞는 경우 그대로 더함
    }
    
    // 음수들의 pairing
    for (int i = 0; i < negatives.size(); i += 2) {
        if (i + 1 < negatives.size())
            result += negatives[i] * negatives[i + 1];
        else {
            // 남은 음수가 있을 경우, 0이 있으면 0과 곱해 상쇄 가능
            if (zeros > 0)
                result += 0;
            else
                result += negatives[i];
        }
    }
    
    // 1은 pairing하지 않고 그대로 더함
    result += ones;
    
    cout << result << "\n";
    return 0;
}