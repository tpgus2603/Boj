//#include<iostream>
//#include<string>
//#include<stack>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	string str;
//	while (1)
//	{
//		stack<char>stk;
//		getline(cin, str);
//		if (str[0] == '.')
//			break;
//		for (auto k : str)
//		{
//			if (k == '[' || k == ']' || k == '(' || k == ')')
//			{
//				if (!stk.empty())
//				{
//					auto t = stk.top();
//					if (t == '[' && k == ']')
//						stk.pop();
//					else if (t == '(' && k == ')')
//						stk.pop();
//					else
//						stk.push(k);
//				}
//				else //ºó°æ¿ì 
//					stk.push(k);
//			}
//		}
//		if (stk.empty())
//			cout << "yes" << '\n';
//		else
//			cout << "no" << '\n';
//	}
//
//
//
//}