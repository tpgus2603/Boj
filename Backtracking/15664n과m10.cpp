#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
int arr[8];
bool isused[8];
vector<int>saved;
void sequence(int cur) //주어진 수열중에서 m개를 택하는 수열 
{
	if (cur == m)
	{
		for (auto k : saved)
			cout << k << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!isused[i])
		{
			if ((cur > 0 && saved[cur-1] <= arr[i]) || cur == 0) //최근에 저장된 요소보다 같거나 큰경우
			{
				isused[i] = 1;
				saved.push_back(arr[i]);
				sequence(cur + 1);
				if (i < n - 1 && saved[cur] == arr[i + 1]) //최근에 저장된 요소와 다음에 저장될 요소가 같다면 
				{
					int temp = saved[cur];
					saved.pop_back();
					isused[i] = 0;
					while (i < n - 1 && temp == arr[i + 1]) //그 요소는 앞으로 저장하지않음 
						i++;
				}
				else {
					saved.pop_back();
					isused[i] = 0;
				}
			}
		}
	}

}
int main()
{
	cin >> n >> m;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr[i] = temp;
	}

	sort(arr, arr + n);
	sequence(0);


}