//#include<iostream>
//#include<vector>
//
////using namespace std;
////
////vector<int> merge(vector<int>&left,vector<int>&right)
////{
////	vector<int> merge;
////	auto it1 = left.begin();
////	auto it2 = right.begin();
////	while (it1!=left.end()|| it2!=right.end()) //둘다 끝날때 까지 계속
////	{
////		if (it1!=left.end()&&(it2 == right.end() ||*it1 <= *it2))
////		{
////			merge.push_back(*it1++);
////		}
////		else
////		{
////			merge.push_back(*it2++);
////		}
////	}
////		return merge;
////}
////
////vector<int> mergesort( const vector<int> &arr)
////{
////	if (arr.size() < 2)
////		return arr;
////	auto center = arr.begin();
////	advance(center, distance(arr.begin(), arr.end()) / 2);
////	auto left = mergesort(vector<int>(arr.begin(),center));
////	auto right = mergesort(vector<int>(center, arr.end()));
////	return merge(left,right);
////}
////int main()
////{
////	vector<int> arr = { 10,4,5,9,11,13,15 };
////	arr=mergesort(arr);
////	for (auto k : arr)
////		cout << k << ' ';
////}
//
////배열에 관한 mergesort
//
//using namespace std;
//
//int n = 10;
//int arr[1000001] = { 15, 25, 22, 357, 16, 23, -53, 12, 46, 3 };
//int tmp[1000001]; // merge 함수에서 리스트 2개를 합친 결과를 임시로 저장하고 있을 변수
//
//// mid = (st+en)/2라고 할 때 arr[st:mid), arr[mid:en)은 이미 정렬이 되어있는 상태일 때 arr[st:mid]와 arr[mid:en]을 합친다.
//void merge(int st, int en) {
//	int mid = (st + en) / 2;
//	int left = mid;
//	int start = st;
//	for (int i = st; i < en; i++)
//	{
//		if (st != mid && (arr[st] <= arr[left] || left == en)) //왼쪽이 끝에 달하기 전까지 가능한 조건문 
//			tmp[i] = arr[st++];
//		else
//			tmp[i] = arr[left++];
//	}
//	for (int i = start; i < en; i++)
//	{
//		arr[i] = tmp[i];
//	}
//}
//
//// arr[st:en]을 정렬하고 싶다.
//void merge_sort(int st, int en) {
//	if (en - st == 1) return; // 길이 1인 경우
//	int mid = (st + en) / 2;
//	merge_sort(st, mid); // arr[st:mid)을 정렬한다.
//	merge_sort(mid, en); // arr[mid:en)을 정렬한다.
//	merge(st, en); // arr[st:mid]와 arr[mid:en]을 합친다.
//}
//
//int main(void) {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	merge_sort(0, n);
//	for (int i = 0; i < n; i++) cout << arr[i] << ' ';  // -53 3 12 15 16 22 23 25 46 357
//}