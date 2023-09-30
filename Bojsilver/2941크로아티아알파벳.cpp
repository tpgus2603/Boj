//#include<stdio.h>
//#include<string>
//#include<iostream>
//using namespace std;
//int main()
//{
//	string word;
//	cin >> word;
//	int cnt = 0;
//	int size = word.size();
//	for (int i = 0; i < size; i++)
//	{
//		if (word[i] == 'c'|| word[i] == 's'|| word[i] == 'z') //c s z인경우 
//		{
//			if (word[i + 1] == '=') //c= z= s=인경우 
//			{
//				cnt++; i++;
//			}
//			else if (word[i] == 'c' && word[i + 1] == '-')  //c-인경우
//			{
//				cnt++; i++;
//			}
//			else cnt++;
//		}
//		else if (word[i] == 'd' ) //d-인경우 
//		{
//			if (word[i + 1] == '-')//d-인경우 
//			{
//				cnt++; i++;
//			}
//			else if (word[i + 1] == 'z' && word[i + 2] == '=') //dz=인경우 2칸이동 
//			{
//				cnt++;
//				i += 2;
//			}
//			else cnt++;
//		}
//		else if (word[i] == 'l' || word[i] == 'n') //l n인경우 
//		{
//			if (word[i + 1] == 'j') //lj nj인경우
//			{
//				cnt++;
//				i++;
//			}
//			else cnt++;
//		}
//		else   cnt++;//나머지 알파벳
//	
//	}
//	cout << cnt;
//
//
//
//}