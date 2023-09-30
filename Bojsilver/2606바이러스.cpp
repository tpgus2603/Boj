//#include<iostream>
//#include<vector>
//#include<queue>
//#include<stack>
//using namespace std;
//vector<int>adj[101];
//bool vis[101];
//int bfs()
//{
//	int cnt = 0;
//	queue<int>q;
//	q.push(1);//시작위치
//	vis[1] = 1; 
//	while (!q.empty())
//	{
//		int cur = q.front();
//		q.pop();
//		for (auto nxt : adj[cur]) {
//			if (!vis[nxt])
//			{
//				q.push(nxt);
//				vis[nxt] = 1;
//				cnt++;
//			}
//		}
//	}
//	return cnt;
//}
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	for (int i = 0; i < k; i++)
//	{
//		int n1, n2;
//		cin >> n1 >> n2;
//		adj[n1].push_back(n2); //양방향 그래프 
//		adj[n2].push_back(n1);
//	}
//	int cnt=bfs();
//	cout << cnt;
//
//}
