#include <iostream>
#include <vector>
#include <cmath>
#include<algorithm>
using namespace std;

int S[20][20];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        cin>>S[i][j];
    }
    int total=1<<N;
    int mindif=0x7fffffff;
    for(int cur=2;cur<total;cur++) //비트마스킹 활용 1인경우 s 0인경우 l
    {
      vector<int> s;
      vector<int> l;
      for(int j=0;j<N;j++)
      {
        int bit=(cur>>j)&1;
        if(bit==1)
          s.push_back(j);
        else
          l.push_back(j);
      }
      int slen=s.size();
      int llen=l.size();
      int ssum=0;
      for(int i=0;i<slen;i++)
      {
        for(int j=i+1;j<slen;j++)
        {
          ssum+=(S[s[i]][s[j]]+S[s[j]][s[i]]);
        }
      }
      int lsum=0;
      for(int i=0;i<llen;i++)
      {
        for(int j=i+1;j<llen;j++)
        {
          lsum+=(S[l[i]][l[j]]+S[l[j]][l[i]]);
        }
      }
      int dif=abs(ssum-lsum);
      mindif=min(mindif,dif);
      if(mindif==0)
        break;
    }
    cout<<mindif;



    return 0;
}