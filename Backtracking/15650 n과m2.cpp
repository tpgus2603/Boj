#include <iostream>
using namespace std;

int n, m;
int arr[8]; //기록
bool isused[9]; //사용여부 

void func(int k) { // 현재 k+1자리수를 택함 
	if (k == m) { // m개를 모두 택했으면
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' '; // arr에 기록해둔 수를 출력
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) { // 1부터 n까지의 수에 대해
		if (!isused[i]){ // 아직 i가 사용되지 않았으면
			if (k != 0 && arr[k - 1] < i)
			{
				arr[k] = i; // k번째 수를 i로 정함
				isused[i] = 1; // i를 사용되었다고 표시
				func(k + 1); // 다음 수를 정하러 한 단계 더 들어감
				isused[i] = 0; //돌아왔으면 다 정한거니 마지막에 채운수 미사용으로 바꿈 
			}
			else if (k == 0)
			{
				arr[k] = i; // k번째 수를 i로 정함
				isused[i] = 1; // i를 사용되었다고 표시
				func(k + 1); // 다음 수를 정하러 한 단계 더 들어감
				isused[i] = 0; //돌아왔으면 다 정한거니 마지막에 채운수 미사용으로 바꿈 
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);
}