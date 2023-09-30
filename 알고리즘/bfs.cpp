//#include <bits/stdc++.h>
//using namespace std;
//#define X first
//#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
//int board[502][502] =
//{{1,1,1,0,1,1,0,0,0,0,0},
// {1,0,0,0,1,1,0,0,0,0,0},
// {1,1,1,0,1,1,0,0,0,0,0},
// {1,1,0,0,1,1,0,0,0,0,0},
// {0,1,0,0,1,0,0,0,0,0,0},
// {0,0,0,0,1,0,0,0,0,0,0},
// {0,0,0,0,1,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응
//bool vis[502][502]; // 해당 칸을 방문했는지
//int dist[502][502]; //시작 위치로부터 떨어진 거리 
//int n = 8, m = 11;
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//
//template <typename T>
//int bfsSerach(queue <T>& q)
//{
//	int sum = 0;
//	while (!q.empty())
//	{
//		pair<int, int>cur = q.front(); q.pop(); sum++;
//		cout << '(' << cur.X << ',' << cur.Y << ')' << "->"; //x가 행 y가 열 
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = cur.X + dx[i];
//			int ny = cur.Y + dy[i];
//			if (nx >= n || nx < 0 || ny >= m || ny < 0)continue;
//			if (vis[nx][ny] || board[nx][ny] != 1)continue;
//			q.push({ nx,ny });
//			vis[nx][ny] = 1;
//			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
//		}
//	}
//	return sum;
//}
//int main()
//{
//	queue<pair<int, int>> q;
//	q.push({ 0,0 });
//	int a=bfsSerach(q);
//	cout << a;
//
//}