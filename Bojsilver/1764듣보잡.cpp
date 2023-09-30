//#include<iostream>
//#include<string>
//#include<map>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	int n, m;
//	cin >> n >> m;
//	map<string, int>stmap;
//	string temp;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		stmap[temp] = 1;
//	}
//	vector<string>arr;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> temp;
//		if (stmap[temp] == 1)
//			arr.push_back(temp);
//	}
//	sort(arr.begin(), arr.end());
//	cout << arr.size() << '\n';
//	for (auto k : arr)
//		cout << k << '\n';
//	
//	
//
//
//
//}