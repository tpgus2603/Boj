//#include<iostream>
//
//using namespace std;
//
//int zero = 0;
//int one = 0;
//int mone = 0;
//
//int arr[3000][3000] = { 2 };
//
//int n;
//void findnum(int num, int row, int col)  //길이와 시작 행 시작 열
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
//		if (k == -1)
//			mone++;
//		else if (k == 0)
//			zero++;
//		else if (k == 1)
//			one++;
//		return;
//	}
//	else
//	{
//		int n1 = num / 3;
//		for (int i = 0; i < 3; i++)
//		{
//			for (int j = 0; j < 3; j++)
//			{
//				findnum(n1, row + n1 * j, col + n1 * i);
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
//	findnum(n, 0,0);
//	cout << mone << '\n';
//	cout << zero << '\n';
//	cout << one << '\n';
//
//
//}