//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	stack<int> stk;
//	ios::sync_with_stdio(0), cin.tie(0);
//	int n;
//	cin >> n;
//	string str;
//	for (int i = 0; i < n; i++)
//	{
//		int k;
//		cin >> str;
//		if (str=="push")
//		{
//			cin >> k;
//			stk.push(k);
//		}
//		else if (str=="pop")
//		{
//			if (stk.empty())
//				cout << -1 << "\n";
//			else {
//				int top = stk.top();
//				stk.pop();
//				cout << top << "\n";
//			}
//		}
//		else if (str=="top")
//		{
//			if (stk.empty())
//				cout << -1 << "\n";
//			else
//				cout << stk.top() << "\n";
//		}
//		else if (str=="size")
//		{
//			cout << stk.size() << "\n";
//		}
//		else if (str=="empty")
//		{
//			if (stk.empty())
//				cout << 1 << "\n";
//			else
//				cout << 0 << "\n";
//		}
//
//	}
//}