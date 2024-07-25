#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

// int main()
// {
//   ios::sync_with_stdio(0);cin.tie(0);
//   map<int,int> m;
//   vector<int> arr;
//   vector<int> arr2;
//   vector<int>ans;
//   int n;
//   cin>>n;
//   int temp;
//   for(int i=0;i<n;i++)
//   {
//     cin>>temp;
//     arr.push_back(temp);
//     arr2.push_back(temp);
//   }
//   sort(arr2.begin(),arr2.end());
//   for(auto temp: arr2)
//   {
//     if(m[temp])continue;
//       m[temp]=m.size();
//   }
//   for(auto temp: arr)
//   {
//     ans.push_back(m[temp]-1);
//   }
//   for(auto temp: ans)
//   {
//     cout<<temp<<' ';
//   }

// }
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  vector<int> arr;
  vector<int> arr2;
  vector<int> set;
  int temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    arr.push_back(temp);
    arr2.push_back(temp);
  }
  sort(arr2.begin(),arr2.end());
  int len =arr2.size();
  for(int i=0;i<len;i++)
  {
    if(i==0||arr2[i-1]!=arr2[i])
      set.push_back(arr2[i]);
  }

  for(auto temp:arr)
  {
    cout<< lower_bound(set.begin(),set.end(),temp)-set.begin()<<' ';
  }


}