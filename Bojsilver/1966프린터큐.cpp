//#include<queue>
//#include<iostream>
//#include<vector>
//#include<utility>
//
//#define X first
//#define Y second
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int testn, n, m;
//	cin >> testn;
//	for (int i = 0; i < testn; i++)
//	{
//		deque<pair<int,int>>queue; //중요도와 순서 삽입 
//		cin >> n >> m;
//		for (int j = 0; j < n; j++)
//		{
//			int temp;
//			cin >> temp; //중요도 
//			queue.push_back({temp,j});
//		}
//		int cnt = 0;//인쇄되는 순서
//		pair<int, int>target = queue[m]; 
//		int k = 0;
//		bool end = true;
//		while (end)
//		{
//
//			for (int i = 0; i < queue.size(); i++)
//			{
//				int max = queue[0].X;
//				for (int a = 0; a < queue.size(); a++) //현재 큐중 제일 높은 중요도 측정 
//				{
//					if (max < queue[a].X)
//						max = queue[a].X;
//				}
//				if (queue[0].X == max) //중요도 제일 큰경우 
//				{
//					if (queue[0] == target) 
//					{
//						end = false;
//						cnt++;
//						break;
//					}
//					else  //일단 큐에서 뺴내고 횟수 증가 
//					{
//						queue.pop_front();
//						cnt++;
//					}
//				}
//				else {//가장큰 경우가 아닌경우 뺴낸뒤 큐의 뒤에 집어넣음
//					auto temp = queue.front();
//					queue.pop_front();
//					queue.push_back(temp);
//				}
//			}
//
//		}
//
//		cout << cnt << '\n';
//	}
//
//
//}