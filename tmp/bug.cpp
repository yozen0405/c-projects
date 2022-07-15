#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int, int>
#define mk make_pair 
using namespace std;

const int maxn = 1e5 + 5;
int n, q;
vector<int> G[maxn];
int p[maxn][19];
int dep[maxn];

void dfs(int u = 1, int par = 0) {
    p[u][0] = par;
    dep[u] = dep[par] + 1;
    for (auto v : G[u]) {
        if (v == par) continue;
        dfs(v, u);
    }
}

pii fnd(int a, int b) {
    pii ret = mk(0, 0); //dep(a) > dep(b)
    int dif = dep[a] - dep[b];
    ret.first = dif;
    ret.second = dif;
    for (int i = 0; i < 19; i++) {
        if (dif & (1 << i)) {
            a = p[a][i];
        }
    }
    if (a == b) return ret;
    for (int i = 18; i >= 0; i--) {
        if (p[a][i] != p[b][i]) {
            a = p[a][i];
            b = p[b][i];
            ret.second += 2 * (1 << i);
            ret.first += (1 << i); 
        }
    }
    ret.second += 2;
    ret.first += 1;
    return ret;
}

int solve(int a, int b, pii dis, int k) {
    int cur = k;
    if (k > dis.first) cur = dis.first;
    k -= dis.first;
    for (int i = 0; i < 19; i++) {
        if (cur & (1 << i)) {
            a = p[a][i];
        }
    }
    if (k > 0) {
        cur = (dis.second - dis.first) - k;
        for (int i = 0; i < 19; i++) {
            if (cur & (1 << i)) {
                b = p[b][i];
            }
        }
    }
    else return a;
    return b;
}

signed main () {
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < 19; j++) {
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
    }
    while (q--) {
        int a, b, k, flg = 0;
        cin >> a >> b >> k;
        if (dep[b] > dep[a]) {
            swap(a, b);
            flg = 1;
        }
        pii ret = fnd(a,b);
        if (k > ret.second){
            cout << -1 << '\n';
            continue;
        }
        if (flg) {
            k = ret.second - k;
        }
        cout << solve(a, b, ret, k) << "\n";
    }

}
