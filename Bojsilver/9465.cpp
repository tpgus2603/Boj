//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int t;
//	cin >> t;
//	for (int i = 0; i < t; i++)
//	{
//		vector<int> arr[2];
//		int n;
//		cin >> n;
//		int temp;
//		for (int j = 0; j < n; j++)
//		{
//			cin >> temp;
//			arr[0].push_back(temp);
//		}
//		for (int j = 0; j < n; j++)
//		{
//			cin >> temp;
//			arr[1].push_back(temp);
//		}
//		int dp[100000][3];
//		dp[0][0] = arr[0][0]; dp[0][1] = arr[1][0];
//		for (int j = 1; j < n; j++)
//		{
//			dp[j][0] = max(dp[j - 1][1], dp[j - 1][2]) + arr[0][j];
//			dp[j][1] = max(dp[j - 1][0], dp[j - 1][2]) + arr[1][j];
//			dp[j][2] = max(dp[j - 1][0], dp[j - 1][1]);
//		}
//		cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';
//
//	}
//
//}