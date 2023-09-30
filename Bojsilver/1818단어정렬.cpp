//#include<stdio.h>
//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//bool strcomp(string a, string b) {
//	if (a.size() != b.size())
//		return  a.size() < b.size();
//	else if (a.size() == b.size())
//		return a < b;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	vector<string> arr;
//	int n;
//	cin >> n;
//	string word;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> word;
//		if(find(arr.begin(),arr.end(),word)==arr.end())
//			arr.push_back(word);
//	}
//	sort(arr.begin(), arr.end(),strcomp);
//	int size = arr.size();
//	for (int i = 0; i < size; i++)
//		cout << arr[i] << "\n";
//
//}