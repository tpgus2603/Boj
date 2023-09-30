//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//bool cmp(int a, int b)
//{
//	return a > b;
//}
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n;
//	cin >> n;
//	vector<int>a;
//	vector<int>b;
//	int temp;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		a.push_back(temp);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		b.push_back(temp);
//	}
//	sort(a.begin(), a.end(), cmp);
//	sort(b.begin(), b.end());
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum += a[i] * b[i];
//	}
//	cout << sum;
//
//
//}