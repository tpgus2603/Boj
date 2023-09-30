//#include<iostream>
//#include<cmath>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//int arr[13] = { 0 };
//bool isused[13];
//vector<int>saved;
//void combination(int cur)
//{
//	if (cur == 6)
//	{
//		for (auto k : saved)
//			cout << k << ' ';
//		cout << '\n';
//		return;
//	}
//	for (int i = 0; arr[i] != 0; i++)
//	{
//		if (!isused[i])
//		{
//			if (cur == 0 || (cur > 0 && saved[cur - 1] < arr[i]))
//			{
//				isused[i] = 1;
//				saved.push_back(arr[i]);
//				combination(cur + 1);
//				saved.pop_back();
//				isused[i] = 0;
//			}
//
//		}
//
//	}
//
//}
//
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int testn;
//	while (1)
//	{
//		cin >> testn;
//		if (testn == 0)
//			break;
//		int temp;
//		for (int i = 0; i < testn; i++)
//		{
//			cin >> temp;
//			arr[i] = temp;
//		}
//		combination(0);
//		for (int i = 0; i < testn; i++)
//			arr[i] = 0;
//		cout << '\n';
//	}
//}
//
////2순열 함수 사용
////int main()
////{
////	ios::sync_with_stdio(0); cin.tie(0);
////	int testn;
////	while (1)
////	{
////		cin >> testn;
////		if (testn == 0)
////			break;
////		int arr[13];
////		for (int i = 0; i < 6; i++)
////			arr[i] = 0;
////		for (int i = 6; i < 13; i++)
////			arr[i] = 1;
////		int temp;
////		vector<int>arr2;
////		for (int i = 0; i < testn; i++)
////		{
////			cin >> temp;
////			arr2.push_back(temp);
////		}
////		do
////		{
////			for (int i = 0; i < testn; i++)
////			{
////				if (arr[i] == 0)
////					cout << arr2[i]<<' ';
////			}
////			cout << '\n';
////		} while (next_permutation(arr,arr+testn));
////		cout << '\n';
////	}
////
////
////}