#include<bits/stdc++.h>
#define ll long long 
#define X first  
#define Y second 
using namespace std;
// int main()
// {
//   ios::sync_with_stdio(0);cin.tie(0);
//   int n;
//   cin>>n;
//   vector<int> arr(n,0);
//   for(int i=0;i<n;i++)
//     cin>>arr[i];
//   sort(arr.begin(),arr.end());
//   vector<pair<short,short>> idx;
//   ll ans=4e9;
//   vector<int> ansarr(3,0);
//   vector<int> sumarr;
//   for(int i=0;i<n-1;i++)
//   {
//     for(int j=i+1;j<n;j++)
//     {
//       sumarr.push_back(arr[i]+arr[j]);
//       idx.push_back({i,j});
//     }
//   }

//   int len=sumarr.size();
//   for(int i=0;i<len;i++)
//   {
//     auto cur=sumarr[i];
//     int x=arr[idx[i].X];
//     int y=arr[idx[i].Y];
//     auto temp=lower_bound(arr.begin(),arr.end(),-1*cur)-arr.begin();
//     if(temp==n)temp--;
//     if(temp+1<n&&abs((ll)cur+(ll)arr[temp+1])<abs(ans)&&arr[temp+1]!=x&&arr[temp+1]!=y)
//     {
//       ans=abs((ll)cur+(ll)arr[temp+1]);
//       ansarr[0]=x;ansarr[1]=y;ansarr[2]=arr[temp+1];
//     }
//     if(abs((ll)cur+(ll)arr[temp])<abs(ans)&&arr[temp]!=x&&arr[temp]!=y)
//     {
//       ans=abs((ll)cur+(ll)arr[temp]);
//       ansarr[0]=x;ansarr[1]=y;ansarr[2]=arr[temp];
//     }
//     temp--;
//     if(temp<0)continue;
//     if(abs((ll)cur+(ll)arr[temp])<abs(ans)&&arr[temp]!=x&&arr[temp]!=y)
//     {
//       ans=abs((ll)cur+(ll)arr[temp]);
//       ansarr[0]=x;ansarr[1]=y;ansarr[2]=arr[temp];
//     }
//   }
//   sort(ansarr.begin(),ansarr.end());
//   for(auto t: ansarr)
//     cout<<t<<' ';
  
// }


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> arr(N);
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    long long best = 3000000001LL; // 최댓값보다 큰 값으로 초기화 (3*1,000,000,000 보다 크게)
    long long ans1, ans2, ans3;

    // 배열에서 하나의 용액을 고정하고 나머지 두 용액을 투포인터로 탐색
    for (int i = 0; i < N - 2; i++){
        int left = i + 1, right = N - 1;
        while (left < right) {
            long long sum = arr[i] + arr[left] + arr[right];
            if (llabs(sum) < best) {
                best = llabs(sum);
                ans1 = arr[i];
                ans2 = arr[left];
                ans3 = arr[right];
            }
            // 합이 0이면 최적의 해이므로 바로 종료
            if (sum == 0) {
                cout << ans1 << " " << ans2 << " " << ans3;
                return 0;
            }
            // 합이 음수이면 left를 증가, 양수이면 right를 감소
            if (sum < 0)
                left++;
            else
                right--;
        }
    }
    
    cout << ans1 << " " << ans2 << " " << ans3;
    return 0;
}