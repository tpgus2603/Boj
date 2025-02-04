#include<bits/stdc++.h>
using namespace std;

#define MAX 1e9
int dp[100001][5][5];       // dp[i][l][r]: i번째 움직임 후 왼발 l, 오른발 r의 최소 힘 소모량
int arr[100001];              

// x에서 y로 이동할 때 사용되는 힘 계산 함수
int power(int x, int y) {
    if(x == y)
        return 1;
    else if(x == 0)
        return 2;
    else if(abs(x - y) == 1 || abs(x - y) == 3)
        return 3;
    else if(abs(x - y) == 2)
        return 4;
    return 0; // 도달하지 않음
}

int main(){
    
    ios::sync_with_stdio(0);cin.tie(0);
    int num, len=1;
    while(1) {
        cin >> num;
        if(num == 0) break;  
        arr[len++] = num;
    }
    len--;  
    for(int i = 0; i <=len; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                dp[i][j][k] = MAX;
            }
        }
    }
    dp[0][0][0]=0;
    //이동전전 발이 dp[i-1][l][r]인경우 
    for(int i=1;i<=len;i++)
    {
      int next=arr[i];
      for(int l=0;l<5;l++)
      {
        for(int r=0;r<5;r++)
        {
          if(dp[i-1][l][r]==MAX)continue;
          //발 유지
          if(l==next||r==next)
          {
            dp[i][l][r]=min(dp[i][l][r],dp[i-1][l][r]+1);
          }
          //왼발이동
          dp[i][next][r]=min(dp[i][next][r],dp[i-1][l][r]+power(l,next));
          //오른발 이동
          dp[i][l][next]=min(dp[i][l][next],dp[i-1][l][r]+power(r,next));
        }
      }
    }
    int ans=MAX;
    for(int i=0;i<5;i++)
    {
      for(int j=0;j<5;j++)
        ans=min(ans,dp[len][i][j]);
    }

  
    cout<<ans;

    return 0;
}