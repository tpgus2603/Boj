//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<vector>
//
//
//using namespace std;
//
//
//struct member {
//	int age;
//	string name;
//	int order;
//
//};
//
//bool strcomp(member a, member b) {
//	if (a.age != b.age)
//		return a.age < b.age;
//	else
//		return a.order < b.order;
//}
//
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n;
//	int age;
//	string name;
//	int order;
//	cin >> n;
//	vector<member>arr;
//	member temp;
//	for (int i = 0; i < n; i++)  
//	{
//		cin >> age >> name;
//		temp.age = age;
//		temp.name = name;
//		temp.order = i;
//		arr.push_back(temp);
//		
//	}
//	sort(arr.begin(), arr.end(),strcomp);
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i].age << " " << arr[i].name << '\n';
//	}
//	
//
//}
//
//
//
//
//
//
//
//
//
//
//
////
////bool strcomp(string a, string b) {
////
////	istringstream iss1(a);
////	istringstream iss2(b);
////	string word1;
////	string word2;
////	vector<string>temp1;
////	vector<string>temp2;
////	while (iss1 >> word1)
////		temp1.push_back(word1); //공백기준 파싱된 문자열 입력
////	while (iss2 >> word2)
////		temp2.push_back(word2);
////	if (temp1[0] != temp2[0])
////		return temp1[0] < temp2[0];
////	else
////		return stoi(temp1[2]) < stoi(temp2[2]);
////
////}
//
//
////int main()
////{
////	ios::sync_with_stdio(0); cin.tie(0);
////	int n;
////	string word;
////	vector<string> arr;
////	cin >> n;
////	while (getchar() != '\n');
////	for (int i = 0; i < n; i++)
////	{
////		getline(cin, word);
////		int index = word.size();
////		string temp = to_string(i);
////		word += " ";
////		word += temp;
////		arr.push_back(word);
////	}
////	sort(arr.begin(), arr.end(), strcomp);
////	for (int i = 0; i < n; i++)
////	{
////		arr[i].pop_back();
////		cout << arr[i] << '\n';
////
////	}
////
////
////}