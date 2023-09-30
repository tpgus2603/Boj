//#include<iostream>
//
//using namespace std;
//
//int arr[3000][3000] = { 2 };
//
//int n;
//void capsul(int num, int row, int col)  //길이와 시작 행 시작 열
//{
//	bool check = true;
//	int k = arr[row][col];
//	for (int i = row; i < row + num; i++)
//	{
//		for (int j = col; j < col + num; j++)
//		{
//			if (arr[i][j] != k)
//			{
//				check = false;
//				break;
//			}
//		}
//	}
//	if (check == true)
//	{
//		if (k == 0)
//			cout << 0;
//		else if (k == 1)
//			cout << 1;
//		return;
//	}
//	else
//	{
//		int n1 = num / 2;
//		for (int i = 0; i < 2; i++)
//		{
//			for (int j = 0; j < 2; j++)
//			{
//				cout << "(";
//				capsul(n1, row + n1 * j, col + n1 * i);
//				cout << ")";
//			}
//		}
//	}
//
//}
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int temp;
//		for (int j = 0; j < n; j++)
//		{
//			cin >> temp;
//			arr[i][j] = temp;
//		}
//	}
//	capsul(n, 0, 0);
//
//}