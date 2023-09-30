//#include <iostream>
//#include<queue>
//#include<utility>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//#define X first
//#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
//
//bool vis[500][500]; // 해당 칸을 방문했는지
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//
//template <typename T>
//int  bfsSerach(queue <T>& q,int board[][500],int n,int m)
//{
//	int sum = 0;
//	int cnt = 0;
//	while (!q.empty())
//	{
//		pair<int, int>cur = q.front(); q.pop();sum++;
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = cur.X + dx[i];
//			int ny = cur.Y + dy[i];
//			if (nx >= n || nx < 0 || ny >= m || ny < 0)continue;
//			if (vis[nx][ny] || board[nx][ny] != 1)continue;
//			q.push({ nx,ny });
//			vis[nx][ny] = 1;
//		}
//	}
//	return sum;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n, m;
//	int num;
//	vector<int> area;
//	queue<pair<int, int>> q;
//	cin >> n >> m;
//	int arr[500][500] = { 0 };
//	for (int i = 0; i < n; i++) //입력 받기 
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> num;
//			arr[i][j] = num;
//		}
//	}
//	int cnt = 0;
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			
//			if(arr[i][j]&&!vis[i][j]) //1에다가 방문 안한놈인경우 
//			{
//				q.push({ i,j });
//				vis[i][j] = 1;
//				sum = bfsSerach(q, arr,n,m);
//				area.push_back(sum);
//			}
//		}
//	}
//	if (area.size() != 0)
//	{
//		cout << area.size() << '\n';
//		cout << *max_element(area.begin(), area.end());
//	}
//	else if(area.size()==0)
//	{
//		cout << 0 << '\n';
//		cout << 0 << '\n';
//	}
//	
//}
//
//
