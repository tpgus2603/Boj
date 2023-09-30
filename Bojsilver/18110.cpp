//#include<iostream>
//#include<deque>
//#include<algorithm>
//#include<cmath>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	deque<int>score;
//	double average=0;
//	int temp;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		score.push_back(temp);
//	}
//	sort(score.begin(), score.end());
//	int cut = round((double)n * 0.15);
//	for (int i = 0; i < cut; i++)
//		score.pop_back();
//	for (int i = 0; i < cut; i++)
//		score.pop_front();
//	int sum = 0;
//	for (auto k : score)
//		sum += k;
//	if(!score.empty())
//		average = round(double(sum) / (double)(n - 2 * cut));
//	cout << (int)average;
//	
//}