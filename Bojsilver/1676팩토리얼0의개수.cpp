//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n;
//	int two = 0;
//	int five = 0;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		int a = i;
//		int b = i;
//		while(a%2==0)
//		{	
//			two++;
//			a /= 2;
//		}
//		while (b%5==0)
//		{
//			five++;
//			b /= 5;
//		}
//	}
//	if (two >= five)
//		cout << five;
//	else
//		cout << two;
//
//
//}