#include<bits/stdc++.h>

#define X first 
#define Y second 
using namespace std;

bool cmp(tuple<int,int,int> a ,tuple<int,int,int> b) //거리,x,y좌표 
{
  int a1,a2,a3;
  int b1,b2,b3;
  tie(a1,a2,a3)=a;
  tie(b1,b2,b3)=b;
  if(a1==b1)
    return a3<b3; //y좌표 작은거
  else
    return a1<b1;

}

int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m,d;
  cin>>n>>m>>d;
  vector<pair<int,int>> enemi;
  int t;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>t;
      if(t==1)
        enemi.push_back({i,j});
    }
  }
  int ans=0;
  vector<int> mask;
  for(int i=0;i<m;i++)
  {
    if(i<3)mask.push_back(0);
    else mask.push_back(1);
  }
  int k=0;
  do
  {
    //cout<<k++<<' ';
    vector<pair<int,int>> arr(enemi.size());
    arr=enemi;
    int cnt=0;
    vector<pair<int, int>> arch;
      for (int i = 0; i < m; i++)
      {
        if (mask[i] == 0)
          arch.push_back({n, i});
      }
    while (!arr.empty())
    {

      set<pair<int, int>> vict;
      for (auto cur : arch)
      {
        vector<tuple<int, int, int>> candi;
        for (auto temp : arr)
        {
          int dis = abs(cur.X - temp.X) + abs(cur.Y - temp.Y);
          if (dis > d)
            continue;
          candi.push_back({dis, temp.X, temp.Y});
        }
        if(candi.empty())continue;
        sort(candi.begin(), candi.end(), cmp);
        int dis, x, y;
        tie(dis, x, y) = candi[0];
        vict.insert({x,y});
      }
      int a=arr.size();
      vector<pair<int,int>> newarr;
      for(auto t: arr)
      {
        if(vict.find(t)==vict.end())
          newarr.push_back(t);
      }
      arr=newarr;
      int b=arr.size();
      cnt+=(a-b);
      // //한킨이동 
      // vector<pair<int,int>> temparr;
      // int len=arr.size();
      // for(int i=0;i<len;i++)
      // {
      //   auto cur=arr[i];
      //   if(cur.X+1>=n)continue;
      //   else temparr.push_back({cur.X+1,cur.Y});
      // }
      // arr=temparr;
      vector<pair<int,int>> temparr;
      int len=arr.size();
      for(int i=0;i<len;i++)
      {
        auto cur=arr[i];
        if(cur.X+1>=n)temparr.push_back(cur); //칸넘어가면 제거대상
        else
          arr[i].X++;
      }
      for(auto t:temparr) //제거대상 제거 
      {
        arr.erase(remove(arr.begin(),arr.end(),t),arr.end());
      }

    }
    ans=max(ans,cnt);
  } while (next_permutation(mask.begin(), mask.end()));

  cout<<ans;
}


// vector<pair<int,int>> move;
//       int len=arr.size();
//       for(int i=0;i<len;i++)
//       {
//         auto cur=arr[i];
//         if(cur.X+1>=n)move.push_back(cur); //칸넘어가면 제거대상
//         else
//           arr[i].X++;
//       }
//       for(auto t:move) //제거대상 제거 
//       {
//         arr.erase(remove(arr.begin(),arr.end(),t),arr.end());
//       }