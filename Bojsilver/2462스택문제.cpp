//#include<iostream>
//#include<deque>
//#include<vector>
//using namespace std;
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n;
//	cin >> n;
//	deque<int> deq;
//	for (int i = 1; i <= n; i++)
//	{
//		deq.push_front(i);
//	}
//	int temp;
//	for (int i = 0; i < n-1; i++)
//	{
//		deq.pop_back();
//		temp = deq.back();
//		deq.pop_back();
//		deq.push_front(temp);
//	}
//	cout << deq.front();
//
//}