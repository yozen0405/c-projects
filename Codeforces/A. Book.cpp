// https://codeforces.com/contest/1572/problem/A
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

const int INF = 0x3f3f3f3f;
const int M = 1e9 + 7;
const int maxn = 2e5 + 5;

int n;
vector<pii> G[maxn];
int in[maxn];

vector<int> topo() {
    queue<int> q;
    vector<int> vec;
    for (int i = 1; i <= n; i++){
        if(!in[i]) {
            q.push(i); 
            vec.push_back(i);
        }
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto [v, w] : G[u]) {
            in[v]--;
            if(!in[v]){
                q.push(v); 
                vec.push_back(v);
            }
        }
    }
    return vec;
}

int solve(vector<int>& tp) {
    vector<int> dp(n + 1);
    int ret = 0;
    for (auto u : tp) {
        for (auto [v, w] : G[u]) {
            dp[v] = max(dp[v], dp[u] + w);
            ret = max(ret, dp[v]);
        }
    }
    return ret;
}

signed main() {
    /*
    要先看某幾頁才能看該頁, 這個相當於一個 graph, 如果要先看 v 才能看 i
    那在圖上就是 v -> i, 如果 v > i, 代表在看完 v 後沒辦法繼續看 i, 要等到下一輪
    v -> i 的邊權就設為 1, 否則邊權就設為 0, 最後因為要考慮 "所有" 的頁數都要看完, 
    所以答案就是 DAG 的 longest path (因為要考慮要最多天才能看完的頁數)
    */
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            G[i].clear();
            in[i] = 0;
        }
        for (int i = 1, u, v; i <= n; i++) {
            int m;
            cin >> m;
            while (m--) {
                cin >> v;
                //先看 v 才能看 i
                G[v].pb(make_pair(i, (i < v)));
                in[i]++;
            }
        }
        vector<int> tp = topo();
        if (tp.size() != n){
            cout << -1 << "\n";
            continue;
        }
        cout << solve(tp) + 1 << "\n";

    }
}
