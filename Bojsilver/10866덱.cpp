//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	deque<int> dque;
//	ios::sync_with_stdio(0), cin.tie(0);
//	int n;
//	cin >> n;
//	string str;
//	for (int i = 0; i < n; i++)
//	{
//		int k;
//		cin >> str;
//		if (str == "push_back")
//		{
//			cin >> k;
//			dque.push_back(k);
//		}
//		if (str == "push_front")
//		{
//			cin >> k;
//			dque.push_front(k);
//		}
//		else if (str == "pop_front")
//		{
//			if (dque.empty())
//				cout << -1 << "\n";
//			else {
//				int front = dque.front();
//				dque.pop_front();
//				cout << front << "\n";
//			}
//		}
//		else if (str == "pop_back")
//		{
//			if (dque.empty())
//				cout << -1 << "\n";
//			else {
//				int back = dque.back();
//				dque.pop_back();
//				cout << back << "\n";
//			}
//		}
//		else if (str == "front")
//		{
//			if (dque.empty())
//				cout << -1 << "\n";
//			else
//				cout << dque.front() << "\n";
//		}
//		else if (str == "back")
//		{
//			if (dque.empty())
//				cout << -1 << "\n";
//			else
//				cout << dque.back() << "\n";
//		}
//		else if (str == "size")
//		{
//			cout << dque.size() << "\n";
//		}
//		else if (str == "empty")
//		{
//			if (dque.empty())
//				cout << 1 << "\n";
//			else
//				cout << 0 << "\n";
//		}
//
//	}
//}