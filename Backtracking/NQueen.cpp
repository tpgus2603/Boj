#include <iostream>
using namespace std;
bool isused1[30]; // 열 을 차지하고 있는지 확인
bool isused2[30]; // 좌측 방향 대각선을 차지하고 있는지
bool isused3[30]; // 우측  방향 대각선을 차지하고 있는지

int cnt = 0;
int n;
void func(int cur) {  //cur은 현재행
   if (cur == n) { // 
       cnt++;
       return;
   }
   for (int i = 0; i < n; i++) { // 0~n-1까지의 열을 순회 
       if (isused1[i] || isused2[i + cur] || isused3[cur - i + n - 1]) // 퀸을 못놓는 자리인경우  n-1은 인덱스가 음수가 안되기 위해
           continue;
       isused1[i] = 1;
       isused2[i + cur] = 1;
       isused3[cur - i + n - 1] = 1;
       func(cur + 1);
       isused1[i] = 0;
       isused2[i + cur] = 0;
       isused3[cur - i + n - 1] = 0;
   }
}
int main(void) {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cin >> n;
   func(0);
   cout << cnt;
}