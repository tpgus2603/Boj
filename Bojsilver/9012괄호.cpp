//#include<iostream>
//#include<string>
//#include<stack>
//using namespace std;
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int t;
//	cin >> t;
//	for (int i = 0; i < t; i++)
//	{
//		stack<char>stk;
//		string str;
//		cin >> str;
//		int size = str.size();
//		for (int j = 0; j < size ; j++)
//		{
//			if (stk.empty())
//				stk.push(str[j]);
//			else
//			{	
//				char temp=stk.top();
//				if (temp == '(' && str[j] == ')')
//					stk.pop();
//				else
//					stk.push(str[j]);
//			}
//		}
//		if (stk.empty())
//			cout << "YES" << '\n';
//		else
//			cout << "NO" << '\n';
//	}
//
//
//}