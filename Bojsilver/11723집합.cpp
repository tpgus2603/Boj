#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

//1������ ������ ������ ǥ���ϱ� ���� �ε����� ������ ����ϴ� �迭 ���� 
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int arr[21] = { 0 };
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string s1;
		int s2;
		cin >> s1;
		if (s1 == "add")
		{
			cin >> s2;
			arr[s2] = 1;
		}
		else if (s1 == "remove")
		{
			cin >> s2;
			if (arr[s2] == 1)
				arr[s2] = 0;
		}
		else if (s1 == "check")
		{
			cin >> s2;
			if (arr[s2]==1) //�����ϴ°�� 
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (s1 == "toggle")
		{
			cin >> s2;
			if (arr[s2] == 1) //�ִ°�� 
				arr[s2] = 0;
			else
				arr[s2] = 1;
		}
		else if (s1 == "all")
		{
			for (int i = 1; i <= 20; i++)
				arr[i] = 1;
		}
		else if (s1 == "empty")
		{
			for (int i = 1; i <= 20; i++)
				arr[i] = 0;
		}


	}



}

//2��Ʈ����ũ�� ���� ������ ������ �����Ѵ� 
#include <iostream>
#include <string>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   int m;
   cin >> m;

   string order;
   int val, BIT = 0; // BIT�� �ݵ�� 0���� �ʱ�ȭ ���ش�.
   while (m--)
   {
       cin >> order;
       if (order == "add")
       {
           cin >> val;
           // or �����ڸ� ���� val��° �ڸ����� 1�� ä���.
           BIT |= (1 << val);
       }
       else if (order == "remove")
       {
           cin >> val;
           // ex) 1000 & ~(1000) = 0000
           BIT &= ~(1 << val); //���� �����Ǵ� ��Ʈ�� ���� 
       }
       else if (order == "check")
       {
           cin >> val;
           if (BIT & (1 << val)) //���� ������ ��Ʈã�� 
               cout << 1 << '\n';
           else
               cout << 0 << '\n';
       }
       else if (order == "toggle")
       {
           cin >> val;
           // BIT�� val��° �ڸ��� 1�̶�� 1^1=0�� �Ǿ� 1->0�� �ǰ�
           // val��° �ڸ��� 0�̶�� 0^1=1 �� �Ǿ� 0 -> 1�� �ȴ�.
           BIT ^= (1 << val);
       }
       else if (order == "all")
       {
           // ex) 10000 - 1 = 1111
           BIT = (1 << 21) - 1;
       }
       else if (order == "empty")
       {
           BIT = 0;
       }
   }

   return 0;
}