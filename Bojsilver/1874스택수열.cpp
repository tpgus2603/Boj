//#include<iostream>
//#include<stack>
//#include<deque>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n;
//	cin >> n;
//	int num;
//	stack<int>stk;
//	deque<char>chr;
//	int poparr[100001] = { 0 };
//	int popn = 0;
//	bool ok = true;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> num;  //1 num까지 push
//		if (i == 1)
//		{
//			for (int j = 1; j <= num; j++)
//			{
//				stk.push(j);
//				chr.push_back('+');
//			}
//			poparr[stk.top()]++;
//			popn++;
//			stk.pop();
//			chr.push_back('-');
//		}
//		else {
//			if (!stk.empty())
//			{
//				if (num > stk.top())
//				{
//					int t = stk.top() + 1;
//					for (int j = t; j <= num; j++)
//					{
//						if(poparr[j]==0)//pop목록에 없는 요소일때
//						{
//							stk.push(j);
//							chr.push_back('+');
//						}
//					}
//					poparr[stk.top()]++;
//					popn++;
//					stk.pop();
//					chr.push_back('-');
//
//				}
//				else if (num == stk.top()) {
//					poparr[stk.top()]++;
//					popn++;
//					stk.pop();
//					chr.push_back('-');
//				}
//				else if (num < stk.top()) ok = false;
//			}
//			else if (stk.empty())//스택이 비어있는 경우 
//			{
//				int max = popn;
//				for (int j = max + 1; j <= num; j++)
//				{
//					stk.push(j);
//					chr.push_back('+');
//				}
//				poparr[stk.top()]++;
//				popn++;
//				stk.pop();
//				chr.push_back('-');
//			}
//		}
//	}
//	if (ok)
//		for (auto k : chr)cout << k << '\n';
//	else
//		cout << "NO";
//
//}