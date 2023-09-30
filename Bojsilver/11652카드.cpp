//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//#define ll long long
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n;
//	cin >> n;
//	vector<ll> arr;
//	ll temp;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		arr.push_back(temp);
//	}
//	sort(arr.begin(), arr.end());
//
//	int cnt = 0;
//	int maxcnt = cnt;
//	int maxidx = 0;
//	for (int i = 1; i < n; i++)
//	{
//		if (arr[i] == arr[i - 1]) //연속된수가 나올떄 cnt증가 
//		{
//			cnt++;
//			if (i == n - 1) //예외 제일큰 수가 여러개일떄
//			{
//				if (maxcnt < cnt) //제일큰수가 가장 많으면 
//				{
//					maxcnt = cnt;
//					maxidx = i;
//				}
//			}
//		}
//		else if (cnt > 0 && arr[i] != arr[i - 1])//다른수가 나올때 카운트 종료
//		{
//			if (maxcnt < cnt)//같은경우는 갱신 x
//			{
//				maxcnt = cnt;
//				maxidx = i-1;
//			}
//			cnt = 0;
//		}
//	}
//	cout << arr[maxidx];
//
//
//
//}