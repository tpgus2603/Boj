//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//#include <utility>
//using namespace std;
//
//int arr[502][502];
//
//int main() {
//	ios::sync_with_stdio(0);cin.tie(0);
//	
//	int N, M, B;
//	int mint = 1e9;
//	int maxh = -1;
//	cin >> N >> M >> B;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			cin >> arr[i][j];
//
//	for (int height = 0; height <= 256; height++) {
//		int save = 0;
//		int remove = 0;
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < M; j++) {
//				int temp = arr[i][j] - height;
//				if (temp < 0) save -= temp;
//				else remove += temp;
//			}
//		}
//		if (remove + B >= save) {
//			int total = 2 * remove + save;
//			if (mint >= total) {
//				mint = total;
//				maxh = height;
//			}
//		}
//	}
//	cout << mint << " " << maxh;
//
//
//
//}