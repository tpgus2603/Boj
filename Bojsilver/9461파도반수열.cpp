//#include<iostream>
//
//using namespace std;
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	long long dp[101];
//	dp[1] = 1;
//	dp[2] = 1;
//	dp[3] = 1;
//	dp[4] = 2;
//	dp[5] = 2;
//	int testn;
//	cin >> testn;
//	for (int i = 6; i <= 100; i++)
//		dp[i] = dp[i - 1] + dp[i - 5];
//	for (int i = 0; i < testn; i++)
//	{
//		int n;
//		cin >> n;
//		cout << dp[n] << '\n';
//	}
//
//}