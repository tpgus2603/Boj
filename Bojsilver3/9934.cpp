#include <bits/stdc++.h>
using namespace std;

int k;
int tree[1025];
int pos=0;
int arr[1025];

void maketree(int depth,int idx)
{
  if(depth>k)return;

  //왼쪽
  maketree(depth+1,idx*2);

  //루트
  tree[idx]=arr[pos++];
  maketree(depth+1,idx*2+1);
}


int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>k;
  int temp= 1<<k;
  for(int i=0;i<temp-1;i++)
  {
    cin>>arr[i];
  }
  maketree(1,1);
  int depth=1;
  for(int i=1;i<temp;i++)
  {
    cout<<tree[i]<<' ';
    if(i+1==1<<depth)
    {
        cout<<'\n';
        depth++;
    }
  }


}
