#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int a, int b) //내림차순 정렬 
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int>lope;
	for (int i = 0; i < n; i++)
	{
		int weight;
		cin >> weight;
		lope.push_back(weight);
	}
	sort(lope.begin(), lope.end(), cmp);
	int maxweigh = lope[0];
	for (int i = 1; i <n; i++)
	{
		if (lope[i] * (i+1) > maxweigh)
			maxweigh = lope[i] * (i+1);
	}
	cout << maxweigh;


}