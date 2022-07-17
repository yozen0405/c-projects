#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mk make_pair
#define pb push_back
using namespace std;

struct node {
    int v, w, a, b, p;
};

const int maxn = 5e4 + 1;
const int lg = 16;
vector<node> G[maxn];
int dep[maxn];
int pr[maxn][lg]; 
int up[maxn][lg][60]; //up[x][i][mod] x go 2^i
int down[maxn][lg][60]; 
// down[x][i][mod] 在 mod 的時候發車, 從 x 上面 2^i 格開始, 因為要配合 par[x][i] 往上的
int vis[maxn];
int n, q;

int nxt(int t, int p, int a) {
    // t cur_time, p 班距, a 首車
    int res = t / p * p + a;
    if (res < t) res += p;
    return res;
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    int dif = dep[a] - dep[b];
    for (int i = 0; i < lg; i++) {
        if (dif & (1 << i)) {
            a = pr[a][i];
        }
    }
    if (a == b) return a;
    for (int i = 0; i < lg; i++) {
        if (pr[a][i] != pr[b][i]) {
            a = pr[a][i];
            b = pr[b][i];
        }
    }
    return pr[a][0];
}

void dfs(int u = 1, int par = -1, int d = 0, node E = {}) {
    dep[u] = d;
    vis[u] = true;
    pr[u][0] = par;
    if (par != -1) {
        for (int i = 0; i <= 59; i++) {
            int st = nxt(i, E.p, E.b);
            up[u][0][i] = (st - i) + E.w; //從下面的上去
            //等候時間 + 搭車時間
        }
        for (int i = 0; i <= 59; i++) {
            int st = nxt(i, E.p, E.a); // 從上面搭下來
            down[u][0][i] = (st - i) + E.w;  
            //if (u == 2) cout << "i:" << i << "," << down[u][0][i] << "\n";
        }
    }
    for (auto e : G[u]) {
        if (!vis[e.v]) dfs(e.v, u, d + 1, e);
    }
}

int UP(int x, int dis, int mod) {
    int ret = 0;
    for (int i = lg - 1; i >= 0; i--) {
        if (dis & (1 << i)) {
            if (ret != 0) ret++;
            ret += up[x][i][(mod + ret) % 60];
            x = pr[x][i];
        }
    }
    return ret;
}

int DN(int x, int dis, int mod) {
    int ret = 0;
    vector<pii> vec;
    for (int i = lg - 1; i >= 0; i--) {
        if (dis & (1 << i)) {
            vec.push_back(mk(x, i)); 
            x = pr[x][i];
        }
    }
    reverse(vec.begin(), vec.end());
    for (auto [cur, i] : vec) {
        if (ret != 0) ret++;
        ret += down[cur][i][(mod + ret) % 60]; 
        //cout << cur << "," << down[cur][i][(mod + ret) % 60] << "\n";
    }
    return ret;
}

void init() {
    cin >> n >> q;
    int u, v, w, a, b, p;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> w >> a >> b >> p;
        G[u].pb({v, w, a, b, p});
        G[v].pb({u, w, b, a, p});
    }
    dfs();
    for (int i = 1; i < lg; i++) {
        for (int x = 1; x <= n; x++) {
            pr[x][i] = pr[pr[x][i - 1]][i - 1];
        }
    }
    for (int i = 1; i < lg; i++) {
        for (int x = 1; x <= n; x++) {
            for (int mod = 0; mod <= 59; mod++) {
                int par = pr[x][i - 1];
                int tmp = up[x][i - 1][mod];
                up[x][i][mod] = tmp + 1 + up[par][i - 1][(mod + 1 + tmp) % 60];
            }
        }
    }
    for (int i = 1; i < lg; i++) {
        for (int x = 1; x <= n; x++) {
            for (int mod = 0; mod <= 59; mod++) {
                int par = pr[x][i - 1];
                int tmp = down[par][i - 1][mod];
                down[x][i][mod] = tmp + 1 + down[x][i - 1][(mod + 1 + tmp) % 60];
            }
        }
    }
}

void solve() {
    int h, m, u, v;
    while (q--) {
        cin >> h >> m >> u >> v;
        int mid = lca(u, v);
        /*
        approach: 
        - go from u to lca
        - go from lca to v
        */
        int ans = 0;
        if (mid == u) {
            cout << DN(v, dep[v] - dep[u], m) << "\n";
        }
        else {
            ans = UP(u, dep[u] - dep[mid], m);
            if (mid != v) {
                ans++;
                ans += DN(v, dep[v] - dep[mid], (ans + m) % 60);
            }
            cout << ans << "\n";
        }
    }
}

signed main() {
    init();
    solve();
}
