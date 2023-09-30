//#include<iostream>
//#include<string>
//#include<list>
//#include<cstdio>
//using namespace std;
//int main() {
//
//	//ios::sync_with_stdio(0), cin.tie(0);
//	string word;
//	cin >> word;
//	list<char> arr;
//	int size = word.size();
//	for (int i = 0; i < size; i++)
//		arr.push_back(word[i]);
//	auto cusor = arr.end(); //문제상으론 문자 사이지만 코드상으로 커서위치는 커서의 오른쪽   문자 
//	
//
//	int n;
//	cin >> n;
//	while (getchar() != '\n');
//	for (int i = 0; i < n; i++)
//	{
//		string str;
//
//		getline(cin, str);
//		if (str[0] == 'L')
//		{
//			if (cusor != arr.begin())
//				cusor--;
//		}
//		else if (str[0] == 'D')
//		{
//			if (cusor != arr.end())
//				cusor++;
//		}
//		else if (str[0] == 'B')
//		{
//			if (cusor != arr.begin()) {
//				cusor--;//삭제할 문자 자리에 위치
//				cusor = arr.erase(cusor);//리스트에서 문자 삭제 후 다음 문자를 가르킴
//			}
//	
//		}
//		else if (str[0] == 'P')
//		{
//			if (cusor == arr.begin())
//			{
//				arr.push_front(str[2]);
//			}
//			else
//				arr.insert(cusor,str[2]);
//
//		}
//
//	}
//	int arrsize = arr.size();
//	auto k = arr.begin();
//	for (int i = 0; i <arrsize; i++)
//	{
//		cout << *k;
//		k++;
//	}
//}