//#include<iostream>
//
//int arr[15][15] = {0};
//bool qexi[15]; //행 
//int cnt[1] = { 0 };
//using namespace std;
//
//int n;
//
//void arrinital(int row)
//{
//	for (int i = 0; i < 15; i++)
//	{
//		
//		arr[row][i] = 0;
//		qexi[row] = 0;
//	}
//}
//
//void nqueen(int row,int col)
//{
//	if (row >= n) //모든행에 퀸 자리 찾으면 
//	{
//		arrinital(row - 1);
//		cnt[0]++;
//		return;
//	}
//	else if (row < 0)
//		return;
//	else {
//		for (int j = col; j < n; j++) //열
//		{
//			bool meet = false;
//			if (!qexi[row])//해당 행에 q이 없는경우 
//			{
//				for (int a = 0; a < n; a++)//해당 자리에 퀸을 놓았을때 만나는지탐색
//				{
//					if (arr[row][a] == 1) //같은 행
//					{
//						meet = true;
//						break;
//					}
//					else if (arr[a][j] == 1) //같은 열
//					{
//						meet = true;
//						break;
//					}
//					else if (j - row + a >= 0)  //대각선 좌
//					{
//						if (arr[a][j - row + a] == 1)
//						{
//							meet = true;
//							break;
//						}
//
//					}
//					else if (row + j - a >= 0)  //대각선 우
//					{
//						if (arr[a][row + j - a] == 1)
//						{
//							meet = true;
//							break;
//						}
//					}
//				}  //퀸 놓을 자리에 퀸이 있는경우 
//				퀸 안만나는 경우
//				if (meet == true)
//				{
//					if (j == n - 1)  //행에서 퀸 놓을 자리 못찾은 경우 이전 행으로 백트랙킹
//					{
//						for (int i = 0; i < n; i++)
//						{
//							if (arr[row - 1][i] == 1)
//							{
//								arr[row - 1][i] = 0;
//								qexi[row - 1] = 0;
//								nqueen(row - 1, i + 1); //이전행으로 백트래킹 돌아온거면 찾은거다.. 그럼 다음행 
//							}
//						}
//					}
//					continue;
//				}
//				arr[row][j] = 1;//퀸 놓기 
//				qexi[row] = 1;
//				nqueen(row + 1, 0); //다음 행에대해 퀸놓기
//				continue;
//			}
//		}
//	}
//}
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	cin >> n;
//	nqueen(0, 0);
//	cout << cnt[0];
//
//
//}
