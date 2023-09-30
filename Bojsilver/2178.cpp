//#include<iostream>
//#include<utility>
//#include<queue>
//#include<string>
//#include<vector>
//#include<stack>
//using namespace std;
//
//#define X first
//#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
//
//bool vis[100][100]; // 해당 칸을 방문했는지
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//vector<pair<int, int>> path;
//template <typename T>
//int bfsSerach(queue <T>& que, int board[][100], int n, int m)
//{
//	int sum = 0;
//	while (!que.empty())
//	{
//		stack<pair<int, int>>stk;
//		pair<int, int>cur = que.front(); que.pop(); sum++;
//		printf("( %d,%d) ->", cur.X+1, cur.Y+1);
//		if (cur.X == n - 1 && cur.Y == m - 1)
//		{
//			printf("\n");
//			return sum;
//		}
//		bool flag = false;
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = cur.X + dx[i];
//			int ny = cur.Y + dy[i];
//			if (nx >= n || nx < 0 || ny >= m || ny < 0)continue;
//			if (vis[nx][ny] || board[nx][ny] != 1)continue;
//			que.push({ nx,ny });
//			vis[nx][ny] = 1;
//		}
//	}
//	return sum;
//}
//int main()
//{
//	int n, m;
//	string num;
//	int arr[100][100] = { 0 };
//	cin >> n >> m;
//	queue <pair<int, int>> que;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> num;
//		for (int j = 0; j < m; j++)
//		{
//			arr[i][j] = num[j] - '0';
//		}
//	}
//	que.push({ 0,0 });
//	vis[0][0] = 1;
//	int sum= bfsSerach(que, arr, n, m);
//	cout << sum;
//
//}