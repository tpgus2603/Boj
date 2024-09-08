#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>


#define S first  
#define T second 

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  priority_queue<int,vector<int>,greater<int>> pq;
  
  int s,t;
  cin>>n;
  vector<pair<int,int>> arr;
  for(int i=0;i<n;i++)
  {
    cin>>s>>t;
    arr.push_back({s,t});
  }
  sort(arr.begin(),arr.end());
  
  for(auto cur: arr)
  {
    if(pq.empty())
      pq.push(cur.T);
    else
    {
      int top=pq.top();
      if(top<=cur.S) //기존 강의실 사용 
      {
        pq.pop();
        pq.push(cur.T);
      }
      else //새로운 강의실 사용 
      {
        pq.push(cur.T);
      }
    }
  }
  cout<<pq.size();



}