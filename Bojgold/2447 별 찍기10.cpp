//#include<iostream>
//#include<cmath>
//#include<string>
//using namespace std;
//
//char arr[10000][10000];
//void starsquare(int n,int row,int col) //시작행 시작 열 
//{
//	if (n == 3)
//	{
//
//		for (int i = row; i < 3+row; i++)
//		{
//			for (int j = col; j <3+col; j++)
//			{
//				if ((i == (2 * row + 3) / 2) && (j == (2 * col + 3) / 2))
//					continue;
//				arr[i][j] = '*';
//			}
//		}
//		return;
//	}
//	if (n > 3)
//	{
//		int n1 = n / 3;
//		for (int i = 0; i < 3; i++)
//		{
//			for (int j = 0; j <3; j++)
//			{
//				if (i == 1 && j == 1)
//					continue;
//				starsquare(n1, row + n1*i, col+n1*j);
//			}
//		}
//
//	}
//}
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//			arr[i][j] = ' ';
//	}
//	starsquare(n, 0, 0);
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//			cout << arr[i][j];
//		cout << '\n';
//	}
//
//}