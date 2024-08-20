#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    
    ios::sync_with_stdio(0);cin.tie(0);
    string str;
    cin >> str;
    
    stack<char> s;
    int ans = 0;
    int len=str.size();
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(') {
            s.push(str[i]);
        } else { // )
            s.pop();
            if (str[i - 1] == '(') { //raser
                ans += s.size();
            }
            else
              ans+=1;
        }
    }
    cout<<ans;
}