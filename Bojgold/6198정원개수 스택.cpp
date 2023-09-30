//#include<stack>
//#include<iostream>
//using namespace std;
//int main()
//{
//	stack<int>stk;
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n,h;
//	cin >> n;
//	long long sum = 0;
//	
//	for (int i = 0; i < n; i++)
//	{
//		cin >> h;   //monostone 새로운 원소가 스택의 최상단 보다 크면  pop하기 
//		while (!stk.empty() && stk.top() <= h) //스택이 비거나 스택 최상단보다 큰경우 제거 작으면 push
//			stk.pop();
//		sum += stk.size();
//		stk.push(h);
//
//	}
//	cout << sum;
//
//}
//
//
//
//
////
////
////int arr[80001] = { 0 };
////ios::sync_with_stdio(0); cin.tie(0);
////int n, h;
////cin >> n;
////int sum = 0;
////for (int i = 1; i <= n; i++)
////{
////	cin >> h;
////	arr[i] = h;//높이 저장 
////}
////for (int i = 1; i <= n; i++)
////{
////	for (int j = i + 1; j <= n; j++)
////	{
////		if (arr[i] > arr[j])
////			sum++;
////		else
////			break;
////	}
////}
////cout << sum;