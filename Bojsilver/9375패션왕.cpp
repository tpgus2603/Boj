//#include<map>
//#include<iostream>
//#include<vector>
//#include<string>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int testn;
//	cin >> testn;
//	for (int i = 0; i < testn; i++)
//	{
//		int n;
//		cin >> n;
//		map<string,int>arr; //옷의종류를 키로 개수를 밸류로 
//		for (int i = 0; i < n; i++)
//		{
//			string item, cloth;//옷이름 과 종류 
//			cin >> item >> cloth;
//			arr[cloth]++;
//		}
//		int num = 1;
//		for (auto k=arr.begin();k!=arr.end();k++)
//		{
//			num *= (k->second + 1);
//		}
//		cout << num - 1<<'\n';
//
//	}
//
//
//}