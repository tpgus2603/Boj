//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int arr[8];
//bool isused[8];
//vector<int>saved;
//int n, m;
//
//void sequence(int cur)
//{
//	if (cur == m)
//	{
//		for (auto k : saved)
//			cout << k << ' ';
//		cout << '\n';
//		return;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (!isused[i])
//		{
//			if ((cur > 0 && saved[cur - 1] < arr[i]) || cur == 0)
//			{
//				isused[i] = 1;
//				saved.push_back(arr[i]);
//				sequence(cur + 1);
//				saved.pop_back();
//				isused[i] = 0;
//			}
//
//		}
//	}
//
//
//
//}
//int main()
//{
//
//	cin >> n >> m;
//	int temp;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		arr[i] = temp;
//	}
//	sort(arr, arr + n);
//	sequence(0);
//
//
//}
