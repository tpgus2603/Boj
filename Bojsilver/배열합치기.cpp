//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n, m;
//	vector<int>arr1;
//	vector<int>arr2;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		int temp;
//		cin >> temp;
//		arr1.push_back(temp);
//	}
//	for (int i = 0; i < m; i++)
//	{
//		int temp;
//		cin >> temp;
//		arr2.push_back(temp);
//	}
//	vector<int>merge;
//	int left = 0; int right = 0;
//	int temp;
//	for (int i = 0; i < n + m; i++)
//	{
//		if (arr1[left] <= arr2[right])temp = arr1[left++];
//		else temp = arr2[right++];
//		merge.push_back(temp);
//		if (left == n )
//		{
//			for (int j = i + 1; j < n + m; j++)
//				merge.push_back(arr2[right++]);
//			break;
//		}
//		else if (right == m )
//		{
//			for (int j = i + 1; j < n + m; j++)
//				merge.push_back(arr1[left++]);
//			break;
//		}
//	}
//	for (auto k : merge)
//		cout << k << " ";
//}

//int n, m;
//int a[1000005], b[1000005], c[2000005];
//
//int main(void) {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) cin >> a[i];
//	for (int i = 0; i < m; i++) cin >> b[i];
//	int aidx = 0, bidx = 0;
//	for (int i = 0; i < n + m; i++) {
//		if (bidx == m) c[i] = a[aidx++];
//		else if (aidx == n) c[i] = b[bidx++];
//		else if (a[aidx] <= b[bidx]) c[i] = a[aidx++];
//		else c[i] = b[bidx++];
//	}
//	for (int i = 0; i < n + m; i++) cout << c[i] << ' ';
//}