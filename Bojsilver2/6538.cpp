#include<iostream>
#include<algorithm>

using namespace std;

bool check[1000001]; //0인경우 소수 
int main()
{
  
  ios::sync_with_stdio(0);cin.tie(0);
  check[1]=true;
  for(int i=2;i<=1000;i++)
  {
    if(check[i])
      continue;
    for(int j=i;j*i<=1000000;j++)
      check[j*i]=true;
  }
  while(1)
  { 
    int n;
    cin>>n;
    if(n==0)break;
    for(int i=3;i<n;i+=2)
    {
      if(check[i]==0&&check[n-i]==0)
      {
        cout<<n<<" = "<<i<<" + "<<n-i<<'\n';
        break;
      }
      if(i==n-1)
        cout<<"Goldbach's conjecture is wrong."<<'\n';
    }
  }


}