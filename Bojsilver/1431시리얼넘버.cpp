//#include<iostream>
//#include<algorithm>
//#include<string>
//#include<vector>
//
//using namespace std;
//
//bool cmp(string a, string b)
//{
//	if (a.size() != b.size()) //길이가 다른경우 
//		return a.size() < b.size();
//	else//길이가 같은경우 
//	{
//		int suma = 0;
//		int sumb = 0;
//		for (int i = 0; i < a.size(); i++)
//		{
//			if (a[i] >= '0' && a[i] <= '9') //숫자일때
//				suma += a[i] - '0';
//		}
//		for (int i = 0; i < b.size(); i++)
//		{
//			if (b[i] >= '0' && b[i] <= '9') //숫자일때
//				sumb += b[i] - '0';
//		}
//		if (suma != sumb)
//			return suma < sumb;
//		else
//			return  a < b;
//	}
//}
//
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//
//	int n;
//	cin >> n;
//	string num;
//	vector<string> arr;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> num;
//		arr.push_back(num);
//	}
//	sort(arr.begin(), arr.end(), cmp);
//	for (auto k : arr)
//		cout << k << '\n';
//
//
//}