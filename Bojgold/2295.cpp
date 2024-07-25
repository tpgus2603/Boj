#include<iostream>
#include<algorithm>
#include<set>
#include<unordered_set>
#include<vector>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  vector<int> arr;
  int temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    arr.push_back(temp);
  }
  int maxn=0;
  vector<int> marr;
  for(auto cur: arr)
  {
    for(auto temp: arr)
    {
      marr.push_back(cur+temp);
    }
  }
  sort(marr.begin(),marr.end());
  for(auto cur: arr)
  {
    for(auto nxt: arr)
    {
      if(binary_search(marr.begin(),marr.end(),cur-nxt))
        maxn=max(maxn,cur);
    }
  }
  cout<<maxn;

}







// int main()
// {
//   ios::sync_with_stdio(0);cin.tie(0);
//   int n;
//   cin>>n;
//   //set<int> s;
//   unordered_set<int>s;
//   int temp;
//   for(int i=0;i<n;i++)
//   {
//     cin>>temp;
//     s.insert(temp);
//   }
//   int maxn=0;
//   //set<int> multiset;
//   unordered_set<int> multiset;
//   for(auto cur: s)
//   {
//     for(auto temp: s)
//     {
//       multiset.insert(cur+temp);
//     }
//   }
//   for(auto cur: s)
//   {
//     for(auto nxt: s)
//     {
//       if(multiset.find(cur-nxt)!=multiset.end())
//         maxn=max(maxn,cur);
//     }
//   }
//   cout<<maxn;
//}

// #include<iostream>
// #include<algorithm>
// #include<set>
// #include<unordered_set>
// #include<unordered_map>
// #define  K first
// #define  V second
// using namespace std;

// int main()
// {
//   ios::sync_with_stdio(0);cin.tie(0);
//   int n;
//   cin>>n;
//   //set<int> s;
//   //unordered_set<int>s;
//   unordered_map<int,int> m;
//   int temp;
//   for(int i=0;i<n;i++)
//   {
//     cin>>temp;
//     m[temp]++;
//   }
//   int maxn=0;
//   //set<int> multiset;
//   //unordered_set<int> multiset;
//   unordered_map<int,int> mmap;
//   for(auto cur:m )
//   {
//     for(auto temp: m)
//     {
//       //multiset.insert(cur+temp);
//       mmap[cur.K+temp.K]++;
//     }
//   }
//   for(auto cur: m)
//   {
//     for(auto nxt: m)
//     {
//       if(mmap[cur.K-nxt.K]!=0)
//         maxn=max(maxn,cur.K);
//     }
//   }
//   cout<<maxn;
// }