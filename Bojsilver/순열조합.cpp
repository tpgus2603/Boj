#include<iostream>
#include<algorithm>

int main()
{
	using namespace std;
	//int arr[4] = { 1,2,3,4 };

	//do {
	//	for (auto k : arr)
	//	{
	//		cout << k<<" ";
	//	}
	//	cout << '\n';
	//} while (next_permutation(arr, arr + 4)); //4개만큼 배열의 순열을 돌린다

	cout << '\n';
	cout << '\n';
	int arr2[4] = { 0,0,1,1 }; //조합 뽑으려는 수만큼 0으로 채워줌 
		do {
			for (int i=0;i<4;i++)
			{
				if (arr2[i] == 0)
				{
					cout << i+1<< " ";
				}
			}
			cout << '\n';
		} while (next_permutation(arr2, arr2 + 4));//4개만큼 배열의 순열을 돌린다

}