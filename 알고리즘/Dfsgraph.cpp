#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<int> adj[10];
bool vis[10];
void dfs()
{
	stack<int>s;
	s.push(1);
	vis[1]=true;
	while(!s.empty())
	{
		int cur=s.top();
		s.pop();
		cout<<cur<<"->";
		for(auto nxt:adj[cur])
		{
			if(!vis[nxt])
			{
				s.push(nxt);
				vis[nxt]=1;
			}
		}
	}
}
void dfsrecur(int cur)
{
	vis[cur]=1;
	cout<<cur<<"->";
	for(auto nxt:adj[cur])
	{
		if(!vis[nxt])
			dfsrecur(nxt);
	}

}
