#include<bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  vector<vector<int>> arr(n,vector<int>(9,0));
  for(int i=0;i<n;i++)
    for(int j=0;j<9;j++)
      cin>>arr[i][j];  
  vector<int> mask;
  for(int i=1;i<9;i++)
    mask.push_back(i);
  bool base[4];
  int maxn=0;
  do
  {
    int score=0;
    for(int i=0;i<4;i++)
      base[i]=false;
    queue<int> order;
    int t=0;
    for(int i=1;i<=9;i++)
    {
      if(i==4)
      {
        order.push(0);
        continue;
      }
      order.push(mask[t++]);
    }
    //각 이닝 시작 
    for(int i=0;i<n;i++)
    { 
      for(int i=0;i<4;i++)
        base[i]=false;
      int out=0;
      while(out<3)
      {
        int cur=order.front();
        //cout<<cur<<' '<<arr[i][cur]<<'\n';
        order.pop();
        order.push(cur);
        switch (arr[i][cur])
        {
          case 0:
            out++;
            break;
          case 1:
            for(int j=3;j>0;j--)
            {
              if(!base[j])continue;
              if(j==3){
                base[j]=false;
                score++;
              }
            }
            for(int j=3;j>1;j--)
            {
              base[j]=base[j-1];
              base[j-1]=false;
            }
            base[1]=true;
            break;
          case 2:
            for(int j=3;j>0;j--)
            {
              if(!base[j])continue;
              if(j>=2){
                base[j]=false;
                score++;
              }
            }
            for(int j=3;j>2;j--)
            {
              base[j]=base[j-2];
              base[j-2]=false;
            }
            base[2]=true;
            break;
          case 3:
            for(int j=3;j>0;j--)
            {
              if(!base[j])continue;
              base[j]=false;
              score++;
            }
            base[3]=true;
            break;
          case 4:
            for(int j=3;j>0;j--)
            {
              if(!base[j])continue;
              base[j]=false;
              score++;
            }
            score++;
            break;
        }
      }
    }
    maxn=max(score,maxn);
  } while (next_permutation(mask.begin(),mask.end()));
  cout<<maxn;



}