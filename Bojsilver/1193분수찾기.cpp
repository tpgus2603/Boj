//#include<stdio.h>
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//  ios::sync_with_stdio(0), cin.tie(0)
//	int n;
//	cin >> n;
//	int sum = 0;
//	int a, b;//분모 분자 
//	for (int i = 1; sum <= 10000 * 2000; i++)
//	{
//		if (n > sum && n <= sum + i)
//		{
//			if (i % 2 == 0) //i가짝수변 진분수로 시작하는 분자 1 분모 i 수열중 하나
//			{
//				int k = (n - sum) % (i+1);  //k번 반복
//				a = i; b = 1;
//				for (int j = 1; j < k; j++)
//				{
//					b++; a--;
//				}
//				break;
//			}
//			else { //i가 홀수면 가분수로 시작  분자 i 분모1 수열 중 하나 
//				int k = (n - sum) % (i+1);
//				a = 1; b = i;
//				for (int j = 1; j < k; j++)
//				{
//					a++; b--;
//				}
//				break;
//			}
//		}
//		sum += i;
//	}
//	printf("%d/%d", b, a);
//
//}