#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n;
vector<string> result;
void func(int k,string cur,int sum,int num,char op) //현재 호출에서 op처리 
{
  if(k>n)
  {
    int temp;
    (op=='+') ? temp=sum+num :temp=sum-num;//마지막에 연산한번 더 처리 
    if(temp==0)
      result.push_back(cur);
    return;
  }
   int temp=0;
   //space
   func(k+1,cur+" "+to_string(k),sum,10*num+k,op);
  (op=='+') ? temp=sum+num :temp=sum-num;
   //+ 
    func(k+1,cur+'+'+to_string(k),temp,k,'+');
   //- 
   func(k+1,cur+'-'+to_string(k),temp,k,'-');

}
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    cin>>n;
    result.clear();
    func(2,"1",0,1,'+');
    sort(result.begin(),result.end());
    for(auto temp :result)
      cout<<temp<<'\n';
    cout<<'\n';
  }

}




// #include <iostream>
// #include <string>

// using namespace std;
// int N;

// void DFS(int step, int sum, int op, int n, string str) {
//     if (step == N) {
//         sum += op * n;
//         if (sum == 0)
//             cout << str << "\n";
//         return;
//     }

//     DFS(step + 1, sum, op, n * 10 + (step + 1), str + ' ' + to_string(step + 1));
//     DFS(step + 1, sum + op * n, 1, step + 1, str + '+' + to_string(step + 1));
//     DFS(step + 1, sum + op * n, -1, step + 1, str + '-' + to_string(step + 1));

// }

// int main(void)
// {
//     int tc; cin >> tc;
//     while (tc--) {
//         cin >> N;
//         DFS(1, 0, 1, 1, "1");
//         cout << "\n";
//     }
// }