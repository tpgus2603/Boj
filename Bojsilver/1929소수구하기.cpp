//#include<iostream>
//#include<vector>
//#include<deque>
//#include<list>
//#define MAX 1000000
//using namespace std;
//
//int arr[MAX + 1]{ 0};
//int main()
//{
//    ios::sync_with_stdio(0); cin.tie(0);
//    int n, m;
//    cin >> n >> m;
//
//    for (int i = 2; i <= m; i++) //소수가 아닌경우 0
//    {
//        arr[i] = i;
//    }
//
//	for (int i = 2; i *i <= m; i++) //2부터 차근차근하기떄문에 j가 n보다 작은경우는 안해도됨 
//	{
//		if (arr[i]==0 )
//			continue;
//		for (int j = i; i*j<=m; j++)
//		{
//			arr[i * j] = 0;
//		}
//
//	}
//
//	for (int i = n; i <= m; i++)
//	{
//		if (arr[i]!=0)
//			cout << arr[i] << '\n';
//	}
//    return 0;
//}





//vector<int> prime;
//
//for (int i = n; i <= m; i++)
//{
//	if (i == 2)
//		prime.push_back(i);
//	bool prim = false;
//	for (int j = 2; j < i; j++)
//	{
//		if (i % j == 0)
//			break;
//		if (j == i - 1)
//			prim = true;
//
//	}
//	if (prim)
//		prime.push_back(i);
//}
//for (auto k : prime)
//cout << k << '\n';

/*ios::sync_with_stdio(0); cin.tie(0);
int n, m;
cin >> n >> m;
list<int>prime;
for (int i = 2; i <= m; i++)
{
	prime.push_back(i);
}
auto it = prime.begin();
auto temp = it;
auto end = prime.end();
while (*it <= m / 2)
{
	it++;
	while (it != end)
	{
		if (*it % *temp == 0)
			it = prime.erase(it);
		else
			it++;
	}
	it = temp;
	temp = ++it;
}
auto it2 = lower_bound(prime.begin(), prime.end(), n);
for (auto i = it2; i != prime.end(); i++)
cout << *i << '\n'*/;



