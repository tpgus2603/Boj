//#include<stdio.h>
//#include<iostream>
//using namespace std;
//int main()
//{
//	int arr[10001] = { 0 };
//
//	for (int i = 1; i <= 10000; i++)
//	{
//		int nselfnum;
//		if (i < 10)
//		{
//			nselfnum = i + i;
//			arr[nselfnum]++;
//		}
//		else if (i >= 10 && i < 100)
//		{
//			nselfnum = i + (i / 10 + i % 10);
//			arr[nselfnum]++;
//		}
//		else if (i >= 100 && i < 1000)
//		{
//			nselfnum = i + (i / 100 + (i / 10) % 10 + i % 10);
//			arr[nselfnum]++;
//		}
//		else{
//			nselfnum = i + (i / 1000 + (i / 100) % 10 + (i / 10) % 10 + i % 10);
//			if (nselfnum <= 10000)
//				arr[nselfnum]++;
//		}
//	}
//	for (int i = 1; i <= 10000; i++)
//	{
//		if (arr[i] == 0)  //selfnumÃâ·Â 
//			printf("%d\n", i);
//	}
//
//
//}