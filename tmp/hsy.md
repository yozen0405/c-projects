```cpp
#include <bits/stdc++.h>
using namespace std;
struct pos{
    int u, s;
};
int T = 0;
array<int, 10> P;
bitset<387420489> vis;
int swap(int u, int i, int j){
    int a, b;
    a = (u / P[i]) % 9;
    b = (u / P[j]) % 9;
    u += (b - a) * P[i];
    u += (a - b) * P[j];
    return u;
}
int bfs(int S){
    int v;
    queue<pos> Q;
    Q.push({S, 0});
    vis[S] = 1;
    while(1){
        auto [u, s] = Q.front();
        Q.pop();
        if(u == T) return s;
        for(int i = 0; i < 9; i++){
            if(i % 3 < 2){
                v = swap(u, i, i + 1);
                if(!vis[v]){
                    Q.push({v, s + 1});
                    vis[v] = 1;
                }
            }
            if(i + 3 < 9){
                v = swap(u, i, i + 3);
                if(!vis[v]){
                    Q.push({v, s + 1});
                    vis[v] = 1;
                }
            }
        }
    }
}
signed main(){
    int x, G = 0;
    P[0] = 1;
    for(int i = 1; i < 10; i++) P[i] = 9 * P[i - 1];
    for(int i = 0; i < 9; i++) T += i * P[i];
    for(int i = 0; i < 9; i++){
        cin >> x;
        G += (x - 1) * P[i];
    }
    cout << bfs(G) << "\n";
    return 0;
}
```
