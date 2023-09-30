//#include<iostream>
//#include<stack>
//using namespace std;
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int k;
//	cin >> k;
//	stack<int>stk;
//	int n;
//	for (int i = 0; i < k; i++)
//	{
//		cin >> n;
//		if (n != 0) stk.push(n);
//		else if (n == 0)
//		{	if(!stk.empty())stk.pop();
//		}
//	}
//	int sum = 0;
//	int size = stk.size();
//	for (int i = 0; i < size; i++)
//	{
//		sum += stk.top();
//		stk.pop();
//	}
//	cout << sum;
//
//
//}