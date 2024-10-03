#include <iostream>

using namespace std;

//비트에서 '1'의 개수를 세는 함수
int countOnes(int n) {
    int count = 0;
    while(n > 0){
        if(n & 1) count++;
        n >>= 1;
    }
    return count;
}

//비트마스킹을 이용한풀이 비트의 1이 합쳐진 물병에해당한다 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n, k;
    cin >> n >> k;
    
    // 초기 '1'의 개수가 k 이하인 경우
    if(countOnes(n) <= k){
        cout << 0;
        return 0;
    }
    
    int x = 0;
    int cur = n;
    
    // 비트를 하나씩 처리 작은비트부터 처리한다 
    for(int bit = 0; bit < 32; bit++){ 
        if(cur & (1 << bit)){ //해당비트가 1인경우 
            
            int add = (1 << bit); //0으로 만들값
            x += add; 
            cur += add;
            // '1'의 개수가 k 이하인지 확인
            if(countOnes(cur) <= k){
                break;
            }
        }
    }
    
    if(countOnes(n + x) <= k){
        cout << x;
    }
    else{
        cout << -1;
    }
}