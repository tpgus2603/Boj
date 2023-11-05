
#include <bits/stdc++.h>
using namespace std;

int n;
int lc[30];
int rc[30];

void preorder(int cur){
  cout << char(cur+'A');
  if(lc[cur] != 0) preorder(lc[cur]);
  if(rc[cur] != 0) preorder(rc[cur]);  
}

void inorder(int cur){
  if(lc[cur] != 0) inorder(lc[cur]);
  cout << char(cur+'A');
  if(rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur){
  if(lc[cur] != 0) postorder(lc[cur]);
  if(rc[cur] != 0) postorder(rc[cur]);
  cout << char(cur+'A');  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    char c,l,r; // cur, left, right
    cin >> c >> l >> r;
    if(l != '.') lc[c-'A'] = l-'A';
    if(r != '.') rc[c-'A'] = r-'A';
  }
  preorder(0); cout << '\n';
  inorder(0); cout << '\n';
  postorder(0); cout << '\n';  
}