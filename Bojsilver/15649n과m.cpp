//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n, m;
//	cin >> n >> m; //n까지 항이 m개인 수열  
//	int arr[9] = { 0 };
//	int dupl[9] = { 0 };//중복아닌경우 0
//	int i = 1;
//	int j = 0;
//	for (i = 1; i <= m; i++) //arr=실제배열에 저장된 수 dupl은 중복여부 i는 자리수 j는 저장될수 
//	{
//		while (++j)
//		{
//			if (j == n + 1)
//			{
//				i -= 1;
//				j = arr[i];
//				for (int k = i; k <= m; k++)
//				{
//					dupl[arr[k]] = 0;
//					arr[k] = 0;
//				}
//				i -= 1;
//				break;
//
//			}
//			if (dupl[j] == 0)
//			{
//				arr[i] = j;
//				dupl[j] = 1;
//				j = 0;
//				break;
//			}
//		}
//		if (i == m) //끝까지 간경우 
//		{
//			for (int k = 1; k <= m; k++)
//				cout << arr[k] << " ";
//			cout << '\n';
//			j = arr[i];
//			dupl[arr[i]] = 0;
//			i -= 1;
//			continue;
//
//		}
//		if (i < 0)
//			break;
//	}
//
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int n, m;
//int arr[8]; //기록
//bool isused[9]; //사용여부 
//
//void func(int k) { // 현재 k+1자리수를 택함 
//	if (k == m) { // m개를 모두 택했으면
//		for (int i = 0; i < m; i++)
//			cout << arr[i] << ' '; // arr에 기록해둔 수를 출력
//		cout << '\n';
//		return;
//	}
//	for (int i = 1; i <= n; i++) { // 1부터 n까지의 수에 대해
//		if (!isused[i]) { // 아직 i가 사용되지 않았으면
//			arr[k] = i; // k번째 수를 i로 정함
//			isused[i] = 1; // i를 사용되었다고 표시
//			func(k + 1); // 다음 수를 정하러 한 단계 더 들어감
//			isused[i] = 0; //돌아왔으면 다 정한거니 마지막에 채운수 미사용으로 바꿈 
//		}
//	}
//}
//
//int main(void) {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> n >> m;
//	func(0);
//}