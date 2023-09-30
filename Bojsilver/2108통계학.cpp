//#include<iostream>
//#include<algorithm>
//#include<cmath>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n;
//	cin >> n;
//	vector<int> arr;
//	vector<int>cnt(n);
//	int num;
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> num;
//		sum += num;
//		arr.push_back(num);
//	}
//
//	double average = round((double)sum / double(n));
//	sort(arr.begin(), arr.end()); //정렬
//	int mid = arr[n / 2]; //중앙값
//	int mode;
//	int range = arr[n - 1] - arr[0];
//	cnt[0] = 1;
//	for (int i = 1; i < n; i++) //요소별로 몇개있는지 세기
//	{	
//		if (arr[i] == arr[i - 1])
//			cnt[i] = cnt[i - 1] + 1; // 중복된거면 이전꺼에+1
//		else
//			cnt[i] = 1;
//	}
//	auto k = max_element(cnt.begin(), cnt.end());
//	vector<int>maxarridx; //최대개수인 인덱스 배열 
//	for (int j=0;j<n;j++)
//	{
//		if (cnt[j] == *k)
//		{
//			maxarridx.push_back(j);
//		}
//	}
//	if (maxarridx.size() == 1)
//	{
//		mode = arr[maxarridx[0]];
//	}
//	else
//	{
//		mode = arr[maxarridx[1]];
//	}
//
//	cout << (int)average << '\n';
//	cout << mid << '\n';
//	cout << mode << '\n';
//	cout << range << '\n';
//
//}