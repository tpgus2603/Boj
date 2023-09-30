//#include<iostream>
//#include<vector>
//#include<queue>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//bool vis[101];
//vector<int>adj[101];//인접행렬 벡터형배열 
//int dist[101];
//
//void bfs(queue<int>& q)
//{
//	fill(dist[0], dist[0] + 100, -1);
//	int cur = q.front();
//	dist[cur] = 0;
//	while (!q.empty())
//	{
//		cur = q.front();
//		vis[cur] = 1;
//		q.pop();
//		cout << cur << "->";
//		for (auto nxt : adj[cur])
//		{
//			if (vis[nxt])continue;
//			q.push(nxt);
//			vis[nxt] = 1;
//			dist[nxt] = dist[cur] + 1;
//		}
//
//	}
//
//}
//int main()
//{
//
//	cout << dist[30];
//
//
//
//}
//
