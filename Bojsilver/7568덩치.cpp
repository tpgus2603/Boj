//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//
//using namespace std;
//
//struct info {
//	int kg;
//	int h;
//	int index;
//	int rank;
//	
//};
//
//
//bool cmp1(info a, info b)
//{
//	if (a.kg != b.kg)  //몸무게 내림차순
//		return a.kg > b.kg;
//	else
//		return a.h > b.h;
//}
//bool cmp2(info a, info b) //인덱스
//{
//	return a.index < b.index;
//}
//
//int main()
//{
//	int n,a,b;
//	vector<info>arr;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a >> b;
//		arr.push_back({ a, b, i });
//	}
//	sort(arr.begin(), arr.end(),cmp1);
//	arr[0].rank = 1;
//	for (int i = 1; i < n; i++)
//	{
//		int cnt = 0;
//		for (int j = 0; j < n; j++)
//		{
//			if (arr[i].kg < arr[j].kg&&arr[i].h < arr[j].h)
//				cnt++;
//		}
//		arr[i].rank = cnt+1;
//
//	}
//	sort(arr.begin(), arr.end(), cmp2);//인덱스 기준 다시정렬
//	for (auto k : arr)
//		cout << k.rank << " ";
//	
//
//}