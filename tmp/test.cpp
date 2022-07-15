#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int INF = 0x3f3f3f3f;
const int M = 1e9 + 7;
const int maxn = 2e5 + 5;
int n, m, k = 4;
vector<int> G[maxn];
int color[maxn];

int colorPaint() {
    for (int i = 1; i <= n; i++) color[i] = 1;
    vector<int> vis(n + 1, 0);
    int mx = 1;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        queue<int> q;
        q.push(i);

        while (q.size()) {
            int u = q.front();
            q.pop();
            for (auto v : G[u]) {
                if (color[v] == color[u]) {
                    color[v]++;
                }
                mx = max(mx, color[v]);
                if (mx > k) return 0;
                if (!vis[i]) {
                    vis[i] = 1;
                    q.push(v);
                }
            }
        }
    }
    return 1;
}

signed main () {
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    cout << colorPaint();
}

/*
4 5
1 2
2 3
3 4
4 2
1 4
true
*/
