//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n, m;
//	
//	cin >> n >> m;
//	vector<string>arr(n);
//	string str;
//	//문자 입력받기 
//	for (int i = 0; i < n; i++)
//	{
//		cin >> str;
//		arr[i] = str;
//	}
//	vector<int>cntarr; //정사각형 개수를 입력받을 배열 
//	int cnt1,cnt2,cnt;
//	for (int i = 0; i <= n - 8; i++)//시작 행 변화
//	{
//		for (int j = 0; j <= m - 8; j++) //시작 열 변화
//		{	
//			cnt1 = 0; cnt2 = 0; cnt; //
//			for (int k = i; k < i + 8; k++)//8x8배열 만들기 행
//			{
//				for (int l = j; l < j + 8; l++)   //열 
//				{
//					if (arr[i][j] == 'B')  //B로시작하는 경우 짝수행 홀수행 나눔 
//					{   //첫번째를  유지하는 케이스는 cnt1으로셈 
//						if (k % 2 == 0)
//						{
//							if (l % 2 == 0)
//							{
//								if (arr[k][l] != 'B') //w인경우
//									cnt1++;
//								else //b인경우 
//									cnt2++;
//							}
//							else
//							{
//								if (arr[k][l] != 'W') 
//									cnt1++;
//								else //b인경우 
//									cnt2++;
//							}
//						}
//						else if (k % 2 == 1)
//						{
//							if (l % 2 == 0)
//							{
//								if (arr[k][l] != 'W') 
//									cnt1++;
//								else  
//									cnt2++;
//							}
//							else
//							{
//								if (arr[k][l] != 'B')
//									cnt1++;
//								else
//									cnt2++;
//							}
//
//						}
//						//W로 바꾸는 경우 cnt2로셈 
//					}
//					else//w로시작하는 경우 
//					{ //w로 유지하는 경우 cnt1
//						if (k % 2 == 0)
//						{
//							if (l % 2 == 0)
//							{
//								if (arr[k][l] != 'W')
//									cnt1++;
//								else  
//									cnt2++;
//							}
//							else
//							{
//								if (arr[k][l] != 'B')
//									cnt1++;
//								else
//									cnt2++;
//
//							}
//
//						}
//						else if (k % 2 == 1)
//						{
//							if (l % 2 == 0)
//							{
//								if (arr[k][l] != 'B')
//									cnt1++;
//								else
//									cnt2++;
//							}
//							else
//							{
//								if (arr[k][l] != 'W')
//									cnt1++;
//								else
//									cnt2++;
//							}
//
//						}
//
//
//					}
//				}
//			}
//			cnt = min(cnt1, cnt2);
//			cntarr.push_back(cnt);
//		}
//	}
//	auto k = min_element(cntarr.begin(), cntarr.end());
//	cout << *k;
//}
//
//
////개선된 코드
////#include <iostream>
////#include <string>
////#include <algorithm>
////#include <utility>
////using namespace std;
////string WB[8] = {
////		"WBWBWBWB",
////		"BWBWBWBW",
////		"WBWBWBWB",
////		"BWBWBWBW",
////		"WBWBWBWB",
////		"BWBWBWBW",
////		"WBWBWBWB",
////		"BWBWBWBW"
////};
////string BW[8] = {
////		"BWBWBWBW",
////		"WBWBWBWB",
////		"BWBWBWBW",
////		"WBWBWBWB",
////		"BWBWBWBW",
////		"WBWBWBWB",
////		"BWBWBWBW",
////		"WBWBWBWB"
////};
////string board[50];
////int WB_cnt(int x, int y)
////{
////	int cnt = 0;
////	for (int i = 0; i < 8; i++)
////	{
////		for (int j = 0; j < 8; j++)
////		{
////			if (board[x + i][y + j] != WB[i][j])
////				cnt++;
////		}
////
////	}
////	return cnt;
////}
////int BW_cnt(int x, int y)
////{
////	int cnt = 0;
////	for (int i = 0; i < 8; i++)
////	{
////		for (int j = 0; j < 8; j++)
////		{
////			if (board[x + i][y + j] != BW[i][j])
////				cnt++;
////		}
////
////	}
////	return cnt;
////}
////int main() {
////	int size[2];
////	int cnt;
////	int min_val = 12345;
////	pair<int, int> p1;
////	cin >> p1.first >> p1.second;
////	for (int i = 0; i < p1.first; i++)
////		cin >> board[i];
////	for (int i = 0; i + 8 <= p1.first; i++)
////	{
////		for (int j = 0; j + 8 <= p1.second; j++)
////		{
////			int tmp;
////			tmp = min(WB_cnt(i, j), BW_cnt(i, j));
////			if (tmp < min_val) {
////				min_val = tmp;
////			}
////		}
////	}
////	cout << min_val;
////	return 0;
////}
