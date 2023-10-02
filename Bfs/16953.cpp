#include<iostream>
#include<queue>
#include<utility>

using namespace std;

#define ll long long


//기존의 그래프의 노드 나 배열상의 좌표를 탐색하는것이 아닌
//조건에 맞는 노드를 큐에 추가하면서 순회한다
int bfs(int a, int b){
    queue <pair <ll, int>> q;
    q.push({a,1});
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        if(cur.first == b){ //탐색 
            return cur.second;
        }
        if(cur.first*2 <= b){
            q.push({cur.first*2, cur.second+1}); 
        }
        if(cur.first*10+1 <= b){
            q.push({cur.first*10 +1, cur.second+1});
        }
    }
    return -1;
}

int main(){
    int a,b;

    cin >> a >> b;
    cout << bfs(a,b);
}