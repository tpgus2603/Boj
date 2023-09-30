//#include<iostream>
//#include<vector>
//#include<cmath>
//
//using namespace std;
//
//int visit( int n,int r,int c)  //r=x c=y
//{
//	int a = pow(2, n - 1); //2^n-1
//	int b = pow(2, n);//2^n
//	
//
//	if (n < 1) //재귀 종료조건 
//		return 0;
//	if (r >= 0 && r < a) //1,2영역
//	{
//		if (c >= 0 && c < a)//1영역
//			return visit(n - 1, r, c);
//		else if (c >= a && c < b) //2영역 
//			return a*a + visit(n - 1, r, c-a);
//	}
//	else if (r >= a && r < b) //3,4,영역 
//	{
//		if (c >= 0 && c < a)//3영역
//			return 2 * a*a + visit(n - 1, r - a, c);
//		else if (c >= a && c < b)
//			return 3 * a*a + visit(n - 1, r - a, c - a);
//	}
//}
//
//int main()
//{
//	int n, r, c; //r행 c열 찾기
//
//	cin >>n>> r >> c;
//	cout << visit(n, r, c) ;
//
//
//}