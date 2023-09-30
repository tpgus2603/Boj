//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n, m;
//	cin >> n;
//	int temp1;
//	vector<int>arr1;
//	vector<int>arr2;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp1;
//		arr1.push_back(temp1);
//	
//	}
//	sort(arr1.begin(), arr1.end());
//	cin >> m;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> temp1;
//		arr2.push_back(temp1);
//	}
//	vector<int>cnt(m);
//	for(int i=0;i<m;i++)
//	{
//		if (binary_search(arr1.begin(), arr1.end(), arr2[i]))
//		{
//			auto it1 = lower_bound(arr1.begin(), arr1.end(), arr2[i]); //지정값 
//			auto it2 = upper_bound(arr1.begin(), arr1.end(), arr2[i]); //지정값보다큰 첫번쨰 
//			int num = distance(it1, it2); //사이에 있는 요소개수 
//			cnt[i] = num;
//		}
//	}
//	for (auto k : cnt)
//		cout << k << " ";
//}