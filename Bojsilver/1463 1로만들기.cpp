//#include<iostream>
//#include<cmath>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//int arr[1000001] = { 0 }; //수가 최대 100만이므로 dp를 이용하여 하나씩 쌓아도 메모리에 지장이없다 
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n;
//	cin >> n;
//	arr[1] = 0;
//	for (int i = 2; i <= n; i++)
//	{
//		arr[i] = arr[i - 1] + 1; //기본은 이전 항에 +1
//		if (i % 2 == 0)arr[i] = min(arr[i], arr[i / 2] + 1); //2의배수인경우 이전의 arr[i]와 arr[i/2]+1중 최소값 고름 
//		if (i % 3 == 0)arr[i] = min(arr[i], arr[i / 3] + 1);
//	}
//
//	cout << arr[n];
//
//}
////for (int i = 2; i <= 1000000; i++) //dp를 이용하여 
////{
////	if (i % 3 == 0)
////	{
////		if (i % 2 == 0)  //6의배수인 경우 
////		{
////			vector<int>minarr = { arr[i / 3],arr[i / 2],arr[i - 1] };
////			auto k = min_element(minarr.begin(), minarr.end());
////			arr[i] = *k + 1;
////		}
////		else if (arr[i / 3] > arr[i - 1]) //일반 3의배수 인경우 
////			arr[i] = arr[i - 1] + 1;
////		else
////			arr[i] = arr[i / 3] + 1;
////	}
////	else if (i % 2 == 0)
////	{
////		if (arr[i / 2] > arr[i - 1]) //2로 나눈 수가 오히려 더 큰경우
////			arr[i] = arr[i - 1] + 1;
////		else
////			arr[i] = arr[i / 2] + 1;
////	}
////	else
////		arr[i] = arr[i - 1] + 1;
////}