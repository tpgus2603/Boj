#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second 
int arr[100][100];
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int r,c,k;
  cin>>r>>c>>k;
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      cin>>arr[i][j];
    } 
  }
  int t=0;
  int rlen=3;
  int clen=3;
  while(t<=100)
  {
    if(arr[r-1][c-1]==k){
      cout<<t;
      return 0;
    }

    if(rlen>=clen) //r연산 행에대해 정렬 
    {
      for(int i=0;i<rlen;i++)
      {
        vector<pair<int,int>> mask; //{등장횟수,수}
        int cnt[101] ={};
        for(int j=0;j<clen;j++)
          cnt[arr[i][j]]++;
        for(int t=1;t<=100;t++)
        {
          if(cnt[t]==0)continue;
          mask.push_back({cnt[t],t});
        }
        sort(mask.begin(),mask.end());
        int t=0;
        for(int j=0;j<mask.size();j++)
        {
          arr[i][t++]=mask[j].Y;
          arr[i][t++]=mask[j].X;
          if(t>=100)break;
        }
        for(int j=t;j<rlen;j++)
          arr[i][j]=0;
      }
    }
    else //l연산 열에 대하여 정렬 
    {
      for(int i=0;i<clen;i++)
      {
        vector<pair<int,int>> mask; //{등장횟수,수}
        int cnt[101] ={};
        for(int j=0;j<rlen;j++)
          cnt[arr[j][i]]++;
        for(int t=1;t<=100;t++)
        {
          if(cnt[t]==0)continue;
          mask.push_back({cnt[t],t});
        }
        sort(mask.begin(),mask.end());
        int t=0;
        for(int j=0;j<mask.size();j++)
        {
          arr[t++][i]=mask[j].Y;
          arr[t++][i]=mask[j].X;
          if(t>=100)break;
        }
        for(int j=t;j<clen;j++)
          arr[j][i]=0;
      }
    }
    //행 개수 세기
    for(int i=0;i<100;i++)
    {
      for(int j=0;j<100;j++)
      {
        if(arr[j][i]==0)break;
        rlen=max(rlen,j+1);
      }
    }
    //열 개수세기 
    for(int i=0;i<100;i++)
    {
      for(int j=0;j<100;j++)
      {
        if(arr[i][j]==0)break;
        clen=max(clen,j+1);
      }
    }
    // for(int i=0;i<4;i++)
    // {
    //   for(int j=0;j<4;j++)
    //     cout<<arr[i][j]<<' ';
    //   cout<<'\n';
    // }
    t++;
  }

  cout<<-1;


}