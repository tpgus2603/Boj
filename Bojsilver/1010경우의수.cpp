//#include<stdio.h>
//#include<iostream>
//#include<algorithm>
//using namespace std;
////다리가 서로 교차되면 안됨 재귀로 풀이->시간초과... 2)조합을 구현
//
//unsigned long long fac(int n) {
//	if (n == 1||n==0)
//		return 1;
//	return n * fac(n - 1);
//}
//int combi(int m, int n)
//{
//	if (m == n)
//		return 1;
//	int k = min(m - n, n);
//	unsigned long long sum = 1;
//	
//	for (int i = 0; i < k; i++)
//			sum *= (m - i);
//	
//	return sum / fac(k);
//}
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	int testn;
//	int n, m;
//	cin >> testn;
//	
//	for (int i = 0; i < testn; i++)
//	{
//		int sum = 0;
//		cin >> n >> m;
//		int dif = m - n;
//		sum = combi(m, n);
//		cout << sum<<"\n";
//	}
//
//}
//
////int getsum(int n, int m) {
////	int sum = 0;
////	int dif = m - n + 1;
////	if (n == 1)
////	{
////		return m;
////	}
////	else if (n == 2)
////	{
////		int k=0;
////		for (int i = 1; i <= dif; i++)
////			k += i;
////		return k;
////	}
////	else {
////		for (int i = 0; i <= m - n; i++)
////			sum += getsum(n-1, m - 1 - i);
////	}
////	return sum;
////}