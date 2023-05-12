#include <iostream>

#include <utility>

#include <vector>

using namespace std;

struct Edge {

    int u, v, w;

};

struct Graph {

    Graph(int n, int s, int t) : s(s), t(t) {

        par = vector<int>(n);

        for (int i = 0; i < n; i++) {

            par[i] = i;

        }

    }

    void add_edge(const Edge& e) {

        int u = find(e.u), v = find(e.v);

        par[u] = v;

    }

    bool connected() {

        return find(s) == find(t);

    }

    void shrink(vector<Edge>& edges) {

        int n = par.size();

        vector<bool> used(n);

        used[find(s)] = true;

        used[find(t)] = true;

        for (Edge e : edges) {

            used[find(e.u)] = true;

            used[find(e.v)] = true;

        }

        vector<int> cc(n, -1);

        int cnt = 0;

        for (int i = 0; i < n; i++) {

            if (i == find(i) && used[i] == true) {

                cc[i] = cnt++;

            }

        }

        for (Edge& e : edges) {

            e.u = cc[find(e.u)];

            e.v = cc[find(e.v)];

        }

        s = cc[find(s)];

        t = cc[find(t)];

        par = vector<int>(cnt);

        for (int i = 0; i < cnt; i++) par[i] = i;

    }

   private:

    int s, t;

    vector<int> par;

    int find(int x) {

        if (par[x] == x) return x;

        return par[x] = find(par[x]);

    }

};

int n, m, x;

vector<Edge> edges;

vector<int> ans;

int s = 0, t;

void init() {

    cin >> n >> m >> t;

    t--;  // to 0-base

    for (int i = 0; i < m; i++) {

        int u, v, w;

        cin >> u >> v >> w;

        u--, v--;  // to 0-base

        w--;

        edges.push_back({u, v, w});

    }

}

// ans[i] : 移除 [i, ans[i]] 不能連通, 移除 [i, ans[i]-1] 可以連通

// 如果移除 [i, emid] 可以連通 \imply emid < ans[i]

// 如果移除 [i, emid] 不能連通 \imply ans[i] <= emid

//

void DC(Graph g, int el, int er, int ql, int qr) {

    // 假設 edges[0, ql-1] 和 edges[er+1, m-1] 都已經加入 g

    // 如果移除 [qr, er] 一定不連通

    if (ql > qr) return;

    if (el == er) {

        for (int i = ql; i <= qr; i++) ans[i] = er;

        return;

    }

    // 先把圖變小

    vector<Edge> edges_old(edges.begin() + ql, edges.begin() + er + 1);

    vector<Edge> edges_new = edges_old;

    g.shrink(edges_new);

    // 把 edge[ql, qr] 換成新編號

    for (int i = 0; i <= er - ql; i++) edges[ql + i] = edges_new[i];

    int emid = (el + er) / 2;

    Graph h = g;

    for (int i = emid + 1; i <= er; i++) {

        h.add_edge(edges[i]);

    }

    int qmid = emid;

    for (int i = ql; i <= emid; i++) {

        if (i > ql) h.add_edge(edges[i - 1]);

        if (h.connected()) {

            // 移除 [i, emid] 會連通

            // 移除 [i-1, emid] 不連通

            qmid = i - 1;

            break;

        }

    }

    Graph gl = g;

    for (int i = emid + 1; i <= er; i++) gl.add_edge(edges[i]);

    DC(gl, el, emid, ql, qmid);  // edge [0, ql-1], [emid+1, m-1]

    Graph gr = std::move(g);

    for (int i = ql; i <= qmid; i++) gr.add_edge(edges[i]);

    DC(gr, emid + 1, er, qmid + 1, qr);  // edge[0, qmid], [er+1,m-1]

    // 把 edge[ql, qr] 換回舊編號

    for (int i = 0; i <= er - ql; i++) edges[ql + i] = edges_old[i];

}

vector<int> color;

vector<vector<pair<int, int>>> wg;

void dfs(int u) {

    for (auto [v, c] : wg[u]) {

        if (color[v] == -1) {

            color[v] = color[u] ^ c;

            dfs(v);

        }

    }

}

int main() {

    cin.tie(0);

    cin.sync_with_stdio(0);

    init();

    if (s == t) {

        cout << n << ' ' << 1 << ' ' << n << ' ' << 1 << '\n';

        return 0;

    }

    int ql = 0, qr = m;

    Graph tmp(n, s, t);

    for (int i = 0; i < m; i++) {

        tmp.add_edge(edges[i]);

        if (tmp.connected()) {

            qr = i;

            break;

        }

    }

    if (qr == m) {

        cout << -1 << '\n';

        return 0;

    }

    //

    ans = vector<int>(m, m);  // 移除 edge[i, ans[i]-1] 之後依然是聯通的

    DC(Graph(n, s, t), 0, m - 1, ql, qr);

    int len = 0, best_l = -1, best_r = -1;

    for (int i = 0; i < m; i++) {

        if (ans[i] - i > len) {

            len = ans[i] - i;

            best_l = i;

            best_r = ans[i] - 1;

        }

    }

    // 重建一張有權重的圖，dfs 判斷 s t 是不是相同顏色

    color = vector<int>(n, -1);

    wg.resize(n);

    for (int i = 0; i < m; i++) {

        if (best_l <= i && i <= best_r) continue;

        Edge e = edges[i];

        wg[e.u].push_back({e.v, e.w});

        wg[e.v].push_back({e.u, e.w});

    }

    color[s] = 0;

    dfs(s);

    // output

    cout << len << ' ';

    cout << best_l + 1 << ' ' << best_r + 1 << ' ';

    cout << color[t] + 1 << '\n';

    return 0;

}

