//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<utility>
//
//#define X first
//#define Y second
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n;
//	cin >> n;
//	vector<pair<int, int>> cnt;
//
//	for (int i = 0; i <= n / 3; i++) //3kg
//	{
//		for (int j = 0; j <= n / 5; j++)  //5kg
//		{
//			if (3 * i + 5 * j == n)
//			{
//				cnt.push_back({ i, j });
//			}
//		}
//	}
//	sort(cnt.begin(), cnt.end());
//	if (cnt.empty())
//		cout << -1;
//	else
//		cout << cnt[0].X + cnt[0].Y;
//
//}