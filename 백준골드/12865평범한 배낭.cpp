//#include<iostream>
//#include<algorithm>
//#include<utility>
//#include<vector>
//#define W first
//#define V second
//
//using namespace std;
//
//int dp[101][100001]={0}; //dp[i][k]i번째 물건 까지 고려했을때 최대적제 무게가 k인가방   최대가치 
//int dpk[101];
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n, k;
//	cin >> n >> k;
//	vector<pair<int, int>>arr;
//	pair<int, int>temp;
//	arr.push_back({ 0, 0 });
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp.W >> temp.V; //무게와 가치 입력받음 
//		arr.push_back(temp);
//	}
//	sort(arr.begin(), arr.end());
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= k; j++)
//		{ 
//			if (j >= arr[i].W) //기존가방에 새로운 물건을 넣을 수 있는 경우 이전의 값이랑 새로 넣었을떄 값중 최대 택하기
//				dp[i][j] = max(dp[i - 1][j - arr[i].W] + arr[i].V, dp[i - 1][j]);
//			else
//				dp[i][j] = dp[i - 1][j];
//		}
//	}
//	cout << dp[n][k];
//
//}
