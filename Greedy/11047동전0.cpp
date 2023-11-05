#include<iostream>
#include<stack>

using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	stack<int>coin;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		coin.push(temp);
	}
	int cnt = 0;
	while (k>0)
	{
		
		cnt += (k / coin.top());
		k %= coin.top();
		
		coin.pop();
	}
	cout << cnt;



}