//#include<iostream>
//#include<list>
//#include<string>
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int testn;
//	string word;
//	cin >> testn;
//	for (int i = 0; i < testn; i++)
//	{
//		list<char>list; //문자 리스트 
//		cin >> word;
//		int size = word.size(); 
//		auto cursor = list.begin();//코드상 커서 위치는 커서의 오른쪽 문자의 반복자 
//		for (int j = 0; j < size; j++) //알파벳인 경우 리스트에 추가 
//		{
//			
//			if (word[j] == '<')
//			{			
//				if (list.size() != 0) {
//					if (cursor != list.begin())
//						cursor--;
//				}
//			}
//			else if (word[j] == '>')
//			{			
//				if (list.size() != 0)
//				{
//					if (cursor !=list.end())
//						cursor++;
//				}
//			}
//			else if (word[j] =='-')
//			{
//				if (cursor != list.begin())
//				{
//					cursor = list.erase(--cursor);
//	
//				}
//			}
//			else //문자나 숫자 입력
//			{
//				list.insert(cursor, word[j]);
//			} //
//		}
//		for (auto a : list)
//			cout << a;
//		cout << "\n";
//	}
//
//}