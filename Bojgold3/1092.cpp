#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include<set>
using namespace std;

bool cmp(int a,int b) //내림차순 
{
  return a>b;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> crain;
  int temp;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    crain.push_back(temp);
  }
  int m;
  cin >> m;
  vector<int>box;
  for(int i=0;i<m;i++)
  {
    cin>>temp;
    box.push_back(temp);
  }
  int maxn;
  sort(box.begin(),box.end(),cmp);
  sort(crain.begin(),crain.end(),cmp);
  if(crain[0]<box[0])
  {
    cout<<-1;
    return 0;
  }
  int s=0;
  while(!box.empty())
  {
    vector<int> result;
    int start=0;
    int len=box.size();
    int left=0,right=0;
    while(left<len&&right<n)
    {
      if(box[left]>crain[right])//못넣는 경우 
        result.push_back(box[left++]);
      else
      {
        left++;right++;
      }
      while(right==n&&left<len)
      {
        result.push_back(box[left++]);
      }
    }
    s++;
    box=result;
  }



cout << s;
}