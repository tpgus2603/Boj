//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int n, m;
//int arr[8];
//vector<int>saved;
//void sequence(int cur) //주어진 수열중에서 m개를 택하는 수열 
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
//		if (cur > 0)
//		{
//			if (saved[cur - 1] <=arr[i])
//			{
//				saved.push_back(arr[i]);
//				sequence(cur + 1);
//				saved.pop_back();
//			}
//		}
//		else
//		{
//			saved.push_back(arr[i]);
//			sequence(cur + 1);
//			saved.pop_back();
//		}
//
//	}
//
//}
//int main()
//{
//	cin >> n >> m;
//	int temp;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		arr[i] = temp;
//	}
//
//	sort(arr, arr + n);
//	sequence(0);
//
//
//}