#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,w,l;
  cin>>n>>w>>l;
  queue<int> rq;
  int temp;
  for(int i=0;i<n;i++){
    cin>>temp;
    rq.push(temp);
  }
  int t=0;
  int sum=0;//하중
  queue<int> cq;//다리
  for(int i=0;i<w;i++)
    cq.push(0);
  while(!rq.empty()||!cq.empty())
  {
    t++;
    sum-=cq.front();
    //cout<<t<<' '<<cq.front()<<'\n';
    cq.pop();
    if(rq.empty())continue;
    int cur=rq.front();
    if(sum+cur>l)
    {
      cq.push(0);
      continue;
    }
    sum+=cur;
    rq.pop();
    cq.push(cur);
  }
  cout<<t;

}