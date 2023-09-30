//#include<string>
//#include<iostream>
//#include<cmath>
//#define R   31
//#define MOD 1234567891
//using namespace std;
//
//long long mod_pow(long long a, long long b) { //오버플로우를 방지하기 위해 모듈러 곱 분배법칙사용 
//	
//	if (b == 0)
//		return 1;
//	long long sum = 1;
//	for (int i = 0; i < b; i++)
//	{
//		sum *= a;
//		sum %= MOD;
//	}
//
//
//	return sum;
//}
//
//
//
//int main()
//{
//	string word;
//	int size = word.size();
//	int n;
//	cin >> n;
//	cin >> word;
//	long long hash = 0;
//	for (int i = 0; i < n; i++)
//	{
//		hash += ((word[i] - 'a' + 1) * mod_pow(R, i));
//	}
//
//	cout << hash % MOD;
//
//
//
//}