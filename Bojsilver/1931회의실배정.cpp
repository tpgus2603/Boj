//#include<iostream>
//#include<algorithm>
//#include<utility>
//#include<vector>
//#include<stack>
//#define X first
//#define Y second
//
//using namespace std;
//
//bool cmp(pair<int, int> a, pair<int, int> b)
//{
//	if (a.Y != b.Y)
//		return a.Y < b.Y; //종료시간 기준 오름차순 
//	else
//		return a.X <b.X;//같다면 시작시간 기준 오름차순  
//}
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n;
//	cin >> n;
//	vector<pair<int, int>>arr;
//	pair<int, int> temp;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp.X; //시작시간
//		cin >> temp.Y; //종료시간 
//		arr.push_back(temp);
//	}
//	sort(arr.begin(), arr.end(), cmp);
//	stack<pair<int, int>>ruse;
//	ruse.push(arr[0]);
//	for (int i = 1; i < n; i++)
//	{
//		if (ruse.top().Y <= arr[i].X)  //마지막에 사용한 강의실의 종료시간보다 시작시간이 늦은경우 추가 
//			ruse.push(arr[i]); //강의실 사용 스택에 넣음 
//	}
//	cout << ruse.size();
//}