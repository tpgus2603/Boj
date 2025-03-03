#include<bits/stdc++.h>
#define X first 
#define Y second 
using namespace std;
int src[51][51];
int arr[51][51];
int n,m;
void func(pair<int,int> a, pair<int,int> b) //a=시작하는 왼족위 b=끝나는 오른쪽아래
{

  int layer=min(b.X-a.X+1,b.Y-a.Y+1)/2;
  for(int i=0;i<layer;i++)
  {
    int left =a.Y+i;
    int right=b.Y-i;
    int top=a.X+i;
    int down=b.X-i;
    vector<int> temp;
    for(int j=left;j<right;j++)
      temp.push_back(arr[top][j]);
    for(int j=top;j<down;j++)
      temp.push_back(arr[j][right]);
    for(int j=right;j>left;j--)
      temp.push_back(arr[down][j]);
    for(int j=down;j>top;j--)
      temp.push_back(arr[j][left]);

    //시계방향 한칸 이동
    int idx=0;
    rotate(temp.begin(),temp.end()-1,temp.end());
    for(int j=left;j<right;j++)
      arr[top][j]=temp[idx++];
    for(int j=top;j<down;j++)
       arr[j][right]=temp[idx++];
    for(int j=right;j>left;j--)
      arr[down][j]=temp[idx++];
    for(int j=down;j>top;j--)
      arr[j][left]=temp[idx++];
  }
}
//1-based 
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int k;
  cin>>n>>m>>k;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
      cin>>src[i][j];
  }
  int r,c,s;
  int t=k;
  vector<pair<pair<int,int>,pair<int,int>>> st;
  while(t--)
  {
    cin>>r>>c>>s;
    pair<int,int> a={r-s,c-s};
    pair<int,int>b={r+s,c+s};
    st.push_back({a,b});
  }
  vector<int>mask(k,0);
  for(int i=0;i<k;i++)
  {
    mask[i]=i;
  }
  int ans=1e9;
  do
  {
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
        arr[i][j]=src[i][j];
    }
    for(int i=0;i<k;i++)
    {
      //mask[i]가 순서
      auto cur=st[mask[i]];
      pair<int,int> a=cur.X;
      pair<int,int>b=cur.Y;
      func(a,b);
    }
    for(int i=1;i<=n;i++)
    {
      int temp=0;
      for(int j=1;j<=m;j++)
      {
        temp+=arr[i][j];
      }
      ans=min(ans,temp);
    }
  } while (next_permutation(mask.begin(),mask.end()));
  
  cout<<ans;

}