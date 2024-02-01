#include<iostream>
#include<algorithm>
#include<string>


using namespace std;

int dp[1001][1001];


int main()
{
  string str1;
  string str2;

  cin>>str1>>str2;
  int strlen1=str1.size();
  int strlen2=str2.size();
  for(int i=0;i<strlen1;i++)
  {
    for(int j=0;j<strlen2;j++)
    {
      if(str2[j]==str1[i])
      {  
        if(j==0)
          dp[i][j]=1;
        else
        { 
          if(i==0)
            dp[i][j]=1;
          else
            dp[i][j]=dp[i-1][j-1]+1;
        }
      }
      else{
        if(j==0)
        {
          if(i==0)
            dp[i][j]=0;
          else  
            dp[i][j]=dp[i-1][j];
        }
        else
        {
          if(i==0)
            dp[i][j]=dp[i][j-1];
          else
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
      }
    }
  }
    cout<<dp[strlen1-1][strlen2-1];
}
