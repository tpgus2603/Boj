#include<iostream>
#include<cmath>
#include<vector>
#define ll long long
#define  K 1000000
using namespace std;
vector<ll>arr;
ll powM(ll a, ll b, ll c) //a^b %c //Ȧ�� ¦���� �������ҵ� 
{
	
	if (b < 1)
		return 1;
	if (b > K)//b�� 100���� �ѱ�� ��� 
	{
		return powM(a,K,c) * powM(a, b -K, c)% c;

	}
	else {
		ll temp = b / 2;
		if (b % 2 == 0)
		{
			if (b == K)  //�鸸�ΰ�� 
			{
				ll temp2 = powM(a, temp, c);
				if (arr.empty())
				{
					arr.push_back((temp2 * temp2)%c);
					return arr[0];
				}
				else
					return arr[0];
			}
			else{
				ll temp2 = powM(a, temp, c);
				return (temp2 * temp2) %c;
			}
		}
		else {
			ll temp2 = powM(a, temp, c);
			return (temp2 * temp2)%c*a%c;
		}

	}

}

int main()
{
	ll a, b, c;
	cin >> a>>b>>c;
	cout << powM(a, b, c);

}



//#include <bits/stdc++.h>
//using namespace std;
//
//using ll = long long;
//
//ll POW(ll a, ll b, ll m) {
//	if (b == 1) return a % m; // �������� 
//	ll val = POW(a, b / 2, m); 
//	val = val * val % m;
//	if (b % 2 == 0) return val; //¦���ΰ�� �׷���
//	return val * a % m; //Ȧ���ΰ�� 
//}