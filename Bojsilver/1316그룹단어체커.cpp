//#include<stdio.h>
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	int testn;
//	int cnt = 0;
//	cin >> testn;
//	for (int i = 0; i < testn; i++)
//	{
//		string word;
//		cin >> word;
//		string temp;
//		temp += word[0];
//		bool group = true;
//		int size = word.size();
//		if (size == 1)
//			cnt++;
//		else {
//			for (int j = 1; j < size; j++)
//			{
//				if (word[j] != word[j - 1]) //알파벳이 바뀜 
//				{
//					if (temp.find(word[j]) == string::npos) //temp에 없는 문자열일때
//						temp += word[j];  
//					else   //temp에 있는 문자일때 그룹문자가 아님 
//					{
//						group = false;
//						break;
//					}
//				}
//			}
//			if (group)
//				cnt++;
//		}
//	}
//	cout << cnt;
//
//}