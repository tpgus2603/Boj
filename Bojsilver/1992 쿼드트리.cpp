//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int arr[65][65] = { 2 };
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
//		cout << "(";
//		for (int i = 0; i < 2; i++)
//		{
//			for (int j = 0; j < 2; j++)
//			{
//				capsul(n1, row + n1 * i, col + n1 * j);
//			}
//		}
//		cout << ")";
//	}
//
//}
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	cin >> n;
//	string temp;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		for (int j = 0; j < n; j++)
//		{
//			arr[i][j] = temp[j]-'0';
//		}
//	}
//	capsul(n, 0, 0);
//
//}