//#include<iostream>
//#include<string>
//#include<vector>
//#include<cctype>
//#include<algorithm>
//#include<map>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n, m;
//	cin >> n >> m;
//	vector<string>arr;
//	map<string, int>intmap;
//	string temp;
//	for (int i = 1; i <=n; i++) //n
//	{
//		cin >> temp;
//		arr.push_back(temp);
//		intmap.insert(make_pair(temp, i));
//	}
//	string ques;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> ques;
//		if (isdigit(ques[0])) //숫자가 들어온경우 o(1)
//		{
//			int key = stoi(ques);
//			cout << arr[key-1] << '\n';
//
//		}
//		else //알파벳이 들어온경우 find시간을 단축하자 log n이내로 
//		{
//			string key = ques;
//			cout << intmap.find(key)->second << '\n';
//		}
//	}
//
//
//
//}