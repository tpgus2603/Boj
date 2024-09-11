#include<algorithm>
#include<stack>
#include<vector>
#include<iostream>

using namespace std;


int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  vector<int> ans(n,-1);
  vector<int> arr;
  int temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    arr.push_back(temp);
  }
  stack<int> s;
  for(int i=n-1;i>=0;i--)
  {
    while(!s.empty()&&s.top()<=arr[i])s.pop();
    if(!s.empty())
    {
      ans[i]=s.top();
    }
    s.push(arr[i]);
  }
  for(auto cur : ans)
  {
    cout<<cur<<' ';
  }


}