//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cmath>
//#include <iterator>
//using namespace std;
//template<typename it,typename T> 
//bool binarysearch(it begin, it end, T a)
//{
//	auto center = begin;
//	advance(center, distance(begin, end) / 2);
//	if (*center == a)
//		return true;
//	if (begin + 1 >= end)  //크기가 1이하가 될때 
//		return false;
//	if (*center > a)
//		return binarysearch(begin, center, a); 
//	else if (*center < a)
//		return binarysearch(center, end, a);
//
//}
//
//
//
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n, m;
//	cin >> n;
//	vector<int>narr(n);
//	int temp;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		narr[i] = temp;
//	}
//	sort(narr.begin(), narr.end());
//	cin >> m;
//	vector<int>marr(m);
//	for (int i = 0; i < m; i++)
//	{
//		cin >> temp;
//		marr[i] = temp;
//	}
//	for (int i = 0; i < m; i++)
//	{
//		//if (binary_search(narr.begin(), narr.end(), marr[i]))
//			//cout << 1 << '\n';
//		if (binarysearch(narr.begin(), narr.end(), marr[i]))
//			cout << 1 << '\n';
//		else
//			cout << 0 << '\n';
//	}
//
//
//}
//
//
//
//
//
////bool binarysearch(const vector<T> &a,const T b)
////{	
////	auto center = a.begin();
////	advance(center, floor(distance(a.begin(), a.end()) / 2));  //center위치 조정 
////	 if (*center == b)
////		return true;
////	 if (a.size() == 1)
////		 return false;//벡터 배열에 생성자의 끝은 포함하지않음
////	 if (*center > b)
////		return binarysearch(vector<T>(a.begin(), center), b); //이 과정에서 시간소모가 큼 
////	 else if (*center < b)
////		return binarysearch(vector<T>(center, a.end()), b);
////}