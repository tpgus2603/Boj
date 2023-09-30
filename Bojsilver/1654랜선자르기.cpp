//#include<iostream>
//#include<vector>
//#include<stack>
//#include<algorithm>
//
//
//using namespace std;
//stack<long long>cnt;
//void binarySearch(vector<int>& arr, int n, long long first, long long end) //랜선의 길이를 이분탐색으로 나눔 
//{
//	if (first >end)//재귀 종료조건에 등호를 붙으면 end에 원하는값이 있는경우 출력이 안됨 
//		return;
//	int size = arr.size();
//	long long sum = 0;
//	long long len = (first + end) / 2;
//	for (int i = 0; i < size; i++)
//	{
//		sum += (arr[i] / len);
//	}
//	if (sum >= n)  //만들어진 랜선 수가 목표보다 적은경우 단위 랜선의 길이 늘려 랜선수 늘리기
//	{
//		cnt.push(len);
//		binarySearch(arr, n, len+1 , end);
//	}
//	else if (sum < n) //랜선의 길이 줄이기 그냥 len경우 끝부분 탐색 불가  
//	{
//		binarySearch(arr, n, first, len-1); >떄문에 len-1
//	}
//}
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	long long k, n, temp;
//	vector<int> arr;
//	cin >> k >> n;
//	for (int i = 0; i < k; i++)
//	{
//		cin >> temp;
//		arr.push_back(temp);
//	}
//	sort(arr.begin(), arr.end());
//	
//	binarySearch(arr, n, 1, arr[k - 1]);
//	long long temp2 = cnt.top();
//	cout << temp2;
//
//	
//}