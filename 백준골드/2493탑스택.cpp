//#include<iostream>
//#include<stack>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n,k;
//	vector<int> arr;
//	stack<int> stk;
//	stack<int>idx;
//	cin >> n;
//	for (int i = 0; i<n; i++) //일단 배열에 
//	{
//		cin >> k;
//		arr.push_back(k);
//	}
//	int temp;
//	idx.push(n);
//	vector<int>cnt(n);
//	for (int i = n-1; i>=0; i--)//왼쪽부터 다시 순회 
//	{
//		temp = arr[i];
// 
//		while (!stk.empty() && temp > stk.top())
//		{
//			stk.pop(); //기존 탑 pop
//			if (i == 0)
//			{
//				cnt[idx.top()] = -1; //첫 원소를 가르키는걸 별도표시 
//				idx.pop();
//			}
//			else {
//				cnt[idx.top()] = i; //기록 
//				idx.pop();
//			}
//		}
//		stk.push(temp); //오름차순으로 stack에 넣기 
//		idx.push(i);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if(cnt[i]==0)
//			cout << cnt[i] << " ";
//		else if (cnt[i] == -1)
//		{
//			cout << 1 << " ";
//		}
//		else
//			cout << cnt[i] + 1 << " ";
//	}
//}