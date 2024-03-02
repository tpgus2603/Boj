#include<iostream>

using namespace std;

int lc[1000001];
int rc[1000001];
void postorder(int root)
{
  if(lc[root]!=0)postorder(lc[root]);
  if(rc[root]!=0)postorder(rc[root]);
  cout<<root<<'\n';
}
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int root;
  cin>>root;
  int t;
  int prev=root;
  while(1)
  {
    int temp=0;
    cin>>temp;
    if(temp==0)break;
    int cur=root;
    while(1)
    {
      if (cur > temp)
      {
        if (lc[cur] == 0) // 왼쪽 자식이 없는경우
        {
          lc[cur] = temp;
          break;
        }
        else
        {
          cur = lc[cur];
        }
      }
      else if(cur<temp)
      {
        if(rc[cur]==0)
        {
          rc[cur]=temp;
          break;
        }
        else{
          cur=rc[cur];
        }
      }
    }
  }
  postorder(root);


}