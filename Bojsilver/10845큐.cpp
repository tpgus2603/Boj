//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	queue<int> que;
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
//			que.push(k);
//		}
//		else if (str=="pop")
//		{
//			if (que.empty())
//				cout << -1 << "\n";
//			else {
//				int top = que.front();
//				que.pop();
//				cout << top << "\n";
//			}
//		}
//		else if (str=="front")
//		{
//			if (que.empty())
//				cout << -1 << "\n";
//			else
//				cout << que.front() << "\n";
//		}
//		else if (str == "back")
//		{
//			if (que.empty())
//				cout << -1 << "\n";
//			else
//				cout << que.back() << "\n";
//		}
//		else if (str=="size")
//		{
//			cout << que.size() << "\n";
//		}
//		else if (str=="empty")
//		{
//			if (que.empty())
//				cout << 1 << "\n";
//			else
//				cout << 0 << "\n";
//		}
//
//	}
//}