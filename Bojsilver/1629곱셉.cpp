//#include<iostream>
//#include<cmath>
//#include<vector>
//#define ll long long
//#define  K 1000000
//using namespace std;
//vector<ll>arr;
//ll powM(ll a, ll b, ll c) //a^b %c //홀수 짝수도 나눠야할듯 
//{
//	
//	if (b < 1)
//		return 1;
//	if (b > K)//b가 100만을 넘기는 경우 
//	{
//		return powM(a,K,c) * powM(a, b -K, c)% c;
//
//	}
//	else {
//		ll temp = b / 2;
//		if (b % 2 == 0)
//		{
//			if (b == K)  //백만인경우 
//			{
//				ll temp2 = powM(a, temp, c);
//				if (arr.empty())
//				{
//					arr.push_back((temp2 * temp2)%c);
//					return arr[0];
//				}
//				else
//					return arr[0];
//			}
//			else{
//				ll temp2 = powM(a, temp, c);
//				return (temp2 * temp2) %c;
//			}
//		}
//		else {
//			ll temp2 = powM(a, temp, c);
//			return (temp2 * temp2)%c*a%c;
//		}
//
//	}
//
//}
//
//int main()
//{
//	ll a, b, c;
//	cin >> a>>b>>c;
//	cout << powM(a, b, c);
//
//}
//
//
//
////#include <bits/stdc++.h>
////using namespace std;
////
////using ll = long long;
////
////ll POW(ll a, ll b, ll m) {
////	if (b == 1) return a % m; // 종료조건 
////	ll val = POW(a, b / 2, m); 
////	val = val * val % m;
////	if (b % 2 == 0) return val; //짝수인경우 그래도
////	return val * a % m; //홀수인경우 
////}