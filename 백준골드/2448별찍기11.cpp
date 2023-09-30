//#include<iostream>
//#include<cmath>
//#include<string>
//using namespace std;
//
//char arr[10000][10000];
//void startree(int n, int row, int col) // 행의길이 분리된 삼각형의 맨위 꼭지점 좌표를 넘겨줌 
//{
//	if (n == 3)
//	{
//
//		for (int i = row; i<row+3;i++)
//		{
//			if (i == row)
//				arr[i][col] = '*';
//			else if (i == row + 1)
//			{
//				arr[i][col - 1] = '*';
//				arr[i][col + 1] = '*';
//			}
//			else if (i == row + 2)
//			{
//				for (int j = col - 2; j <= col + 2; j++)
//					arr[i][j] = '*';
//			}
//		}
//		return;
//	}
//	if (n > 3)
//	{
//		int n1 = n / 2;
//		startree(n1,row,col);
//		startree(n1, row+n1, col - n1);
//		startree(n1, row+n1, col + n1);
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
//		for (int j = 0; j < n*2; j++)
//			arr[i][j] = ' ';
//	}
//	startree(n, 0, n-1);
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n*2; j++)
//			cout << arr[i][j];
//		cout << '\n';
//	}
//
//}