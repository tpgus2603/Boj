//#include<vector>
//#include<iostream>
//using namespace std;
//int n = 15;
//int arr[1000001] = { 0 };
//int d = 3;
//int p10[3];
//int digitnum(int x, int a)
//{
//	return (x / p10[a]) % 10; //10^a자리의 자리수 
//}
//vector<int>l[10]; //가능한 자리수 0~9 리스트 
//int main()
//{
//	p10[0] = 1;
//	for (int i = 1; i < d; i++)p10[i] = p10[i - 1] * 10;
//	for (int i = 0; i < d; i++) //
//	{
//		for (int j = 0; j < 10; j++)l[j].clear();
//		for (int j = 0; j < n; j++)
//			l[digitnum(arr[j], i)].push_back(arr[j]); //i자리의 자리수 
//		int aidx = 0;
//		for (int j = 0; j < 10; j++) {
//			for (auto x : l[j])arr[aidx++] = x; //새로운 순서로 배열에 넣기 
//		}
//	}
//
//
//}