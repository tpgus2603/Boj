//#include<iostream>
//#include<string>
//#include<unordered_set>
//
//using namespace std;
//
////1유한한 범위의 집합을 표현하기 위해 인덱스를 값으로 취급하는 배열 만듬 
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	int arr[21] = { 0 };
//	int m;
//	cin >> m;
//	for (int i = 0; i < m; i++)
//	{
//		string s1;
//		int s2;
//		cin >> s1;
//		if (s1 == "add")
//		{
//			cin >> s2;
//			arr[s2] = 1;
//		}
//		else if (s1 == "remove")
//		{
//			cin >> s2;
//			if (arr[s2] == 1)
//				arr[s2] = 0;
//		}
//		else if (s1 == "check")
//		{
//			cin >> s2;
//			if (arr[s2]==1) //존재하는경우 
//				cout << 1 << '\n';
//			else
//				cout << 0 << '\n';
//		}
//		else if (s1 == "toggle")
//		{
//			cin >> s2;
//			if (arr[s2] == 1) //있는경우 
//				arr[s2] = 0;
//			else
//				arr[s2] = 1;
//		}
//		else if (s1 == "all")
//		{
//			for (int i = 1; i <= 20; i++)
//				arr[i] = 1;
//		}
//		else if (s1 == "empty")
//		{
//			for (int i = 1; i <= 20; i++)
//				arr[i] = 0;
//		}
//
//
//	}
//
//
//
//}
//
////2비트마스크를 통해 집합을 빠르게 연산한다 
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int m;
//    cin >> m;
//
//    string order;
//    int val, BIT = 0; // BIT를 반드시 0으로 초기화 해준다.
//    while (m--)
//    {
//        cin >> order;
//        if (order == "add")
//        {
//            cin >> val;
//            // or 연산자를 통해 val번째 자리수를 1로 채운다.
//            BIT |= (1 << val);
//        }
//        else if (order == "remove")
//        {
//            cin >> val;
//            // ex) 1000 & ~(1000) = 0000
//            BIT &= ~(1 << val); //값과 대응되는 비트를 없앰 
//        }
//        else if (order == "check")
//        {
//            cin >> val;
//            if (BIT & (1 << val)) //값과 대응는 비트찾기 
//                cout << 1 << '\n';
//            else
//                cout << 0 << '\n';
//        }
//        else if (order == "toggle")
//        {
//            cin >> val;
//            // BIT의 val번째 자리가 1이라면 1^1=0이 되어 1->0이 되고
//            // val번째 자리가 0이라면 0^1=1 이 되어 0 -> 1이 된다.
//            BIT ^= (1 << val);
//        }
//        else if (order == "all")
//        {
//            // ex) 10000 - 1 = 1111
//            BIT = (1 << 21) - 1;
//        }
//        else if (order == "empty")
//        {
//            BIT = 0;
//        }
//    }
//
//    return 0;
//}