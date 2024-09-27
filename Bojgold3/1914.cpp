#include<iostream>
#include<math.h>
#include<string>
#define ll long long 
using namespace std;

int n;

void hanoi(int cur,int from ,int by, int to)
{
  if(cur==1)
  {
    cout<<from<<' '<<to<<'\n';
    return;
  }
  hanoi(cur-1,from,to,by);
  cout<<from<<' '<<to<<'\n';
  hanoi(cur-1,by,from,to);
  return ;
}
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin >> n;
  // string ans=to_string(pow(2,n));
  // ans=ans.substr(0,ans.find('.'));
  // ans[ans.length()-1]-=1; //2의배수여서 가능... 1의자리가 0인ㅂ
  // cout<<ans<<'\n';
  // cout<<to_string(pow(2,100)-1000000)<<'\n';
  cout<<pow(2,100)<<'\n';
  if(n<=20)
    hanoi(n,1,2,3);
}