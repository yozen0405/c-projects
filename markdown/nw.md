## CSES Planets Queries II

## 題意

- 無向圖輸出環

> 頂環樹 $\texttt{:}$
>
> - 圖上只有一個環
> - 每個 $\texttt{node}$ 的 $\texttt{out degree}$ 都至少是 $1$
>   - 所以可以一直走，不可能會有一個結尾的點，也就代表有一個環
>   - 若有結尾的點代表該點 $\texttt{out degree}$ 是 $0$ ， 矛盾

## 想法

- 先假設 $u \rightarrow v$ 是 $\texttt{POSSIBLE}$ 的而且頂環樹本身就是一個環
- 我們把環放在一個陣列上

![image-20221129185824012](C:\Users\yozen\AppData\Roaming\Typora\typora-user-images\image-20221129185824012.png)

- 我們只需要把 $\texttt{node}$ 標上他的 $\texttt{dis[u]}$ 即可



## CODE

```cpp
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mk make_pair
#define F first
#define S second
using namespace std;
 
const int INF = 2e18;
const int maxn = 1e5 + 5;
int n, m;
vector<int> G[maxn];
int pre[maxn];
vector<int> ans;
 
void dfs (int u, int par) {
    for (auto v : G[u]) {
        if (v == par) continue;
        if (pre[v]) { // if (visited[v])
            ans.pb(u);
            while (ans.back() != v) { // backtracking
                ans.pb(pre[ans.back()]);
            }
            ans.pb(u);
            cout << ans.size() << "\n";
            for (int ele : ans) cout << ele << " ";
            exit(0);
        }
        pre[v] = u;
        dfs (v, u);
    }
}
 
void init () {
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
}
 
void solve () {
    for (int i = 1; i <= n; i++) {
        if (!pre[i]) {
            pre[i] = i;
            dfs (i, 0);
        }
    }
    cout << "IMPOSSIBLE\n";
}
 
signed main () {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    init ();
    solve ();
}
```

