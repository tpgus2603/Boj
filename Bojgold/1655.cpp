#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  priority_queue<int,vector<int>> max_pq; //작은 녀석들 maxpq에넣기 
  priority_queue<int,vector<int>,greater<int>>min_pq; //->큰녀석들 minpq에
  for(int i=0;i<n;i++)
  {
    int temp;
    cin>>temp;
    if(min_pq.size()>=max_pq.size())   // max_pq크기가 같거나 더 많게됨(짝수의 경우 작은걸 반환해야하기에)
      max_pq.push(temp);
    else
      min_pq.push(temp);
    if(!min_pq.empty()&&max_pq.top()>min_pq.top()) //pq크기 조절
    {
      min_pq.push(max_pq.top());
      max_pq.pop();
      max_pq.push(min_pq.top());
      min_pq.pop();
    }

    cout<<max_pq.top()<<'\n';

  }



}