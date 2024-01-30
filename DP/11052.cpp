#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

#define VPN first
#define INDEX second
int n;
int arr[1001];
int dp[1001];
using namespace std;


int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  
  dp[1]=arr[1];
  for(int i=2;i<=n;i++)
  {
    int max=0;
    dp[i]=arr[i];
    for(int j=1;j<=i;j++)
    {
      if(max<=dp[j]+arr[i-j])
        max=dp[j]+arr[i-j];
    }
    dp[i]=max;
  }
  cout<<dp[n];
}





// bool cmp(pair<double,int> a ,pair<double,int> b)
// {
//   return a.first>b.first;
// }

// int main()
// {
//   ios::sync_with_stdio(0);cin.tie(0);
//   cin>>n;
//   vector<pair<double,int>> mark;
//   for(int i=1;i<=n;i++)
//     {
//       cin>>arr[i];
//       mark.push_back({(double)arr[i]/i,i});
//     }
//     sort(mark.begin(),mark.end(),cmp);
//     int temp=n;
//     int idx=0;
//     int cost=0;
//     while(temp)
//     {
//       if(temp-mark[idx].INDEX>=0)
//       {
//         temp-=mark[idx].INDEX;
//         cost+=arr[mark[idx].INDEX];
//       }
//       else
//         idx++;
//     }
//     cout<<cost;


// }