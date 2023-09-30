//#include<iostream>
//
//using namespace std;
//#include<iostream>
//
//using namespace std;
//int cnt[1] = { 0 };
//
//
//void hanoicnt(int n,int from,int by, int to) {//출발 경유 도착
//	
//	if (n == 1)
//	{
//		cnt[0]++;
//		return;
//	}
//	hanoicnt(n - 1,from,to,by);
//	cnt[0]++;
//	hanoicnt(n - 1,by,from,to);
//}
//void hanoi(int n, int from, int by, int to) {// 1 2 3 
//
//	if (n == 1)
//	{
//		cout << from << ' ' << to << '\n';
//		return;
//	}
//	hanoi(n - 1, from, to, by);
//
//	cout << from << ' ' << to << '\n';
//
//	hanoi(n - 1, by, from, to);
//
//}
//
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n;
//	cin >> n;
//	hanoicnt(n,1,2,3);
//	cout << cnt[0]<<'\n';
//	hanoi(n,1,2,3);
//	return 0;
//}