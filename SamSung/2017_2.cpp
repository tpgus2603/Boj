#include<bits/stdc++.h>

#define X first 
#define Y second
using namespace std;
vector<pair<int,int>> day;
int n,t;
int answer;
void func(int cur,int sum) //현재날짜 1-based 
{
  if(cur>n+1)return;
  answer=max(answer,sum);
  if(cur==n+1)return;
  func(cur+day[cur].X,sum+day[cur].Y);
  func(cur+1,sum);
}
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  int a,b;
  day.push_back({0,0});
  for(int i=0;i<n;i++)
  {
    cin>>a>>b;
    day.push_back({a,b});
  }
  func(1,0);
  cout<<answer;

}