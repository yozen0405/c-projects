```cpp=
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define ALL(x) x.begin(), x.end()
 
using namespace std;
using PQ = priority_queue<int, vector<int>, greater<int>>;
 
const int INF = 2e18;
const int maxn = 3e5 + 5;
const int M = 1e9 + 7;
const int K = 60;

int n, tar;
vector<int> a;

void init () {
    cin >> n >> tar;
    a.clear ();
    a.resize (n);
    for (int i = 0; i < n; i++) cin >> a[i];
}

void solve () {
    vector<int> v(K, -1);
    int j = 0;
    for (int x : a) {
        j++;
        for (int i = 0; i < K; i++) {
            if (v[i] != -1 && (x & (1LL << i))) {
                //cout << "idx:" << j << ",i:" << i << "\n";
                x ^= v[i];
            }
        }
        if (x == 0) continue;
        int p = K;
        while ((x & (1LL << p)) == 0) p--;
        //cout << "p:" << p << ",x:" << x << "\n";
        v[p] = x;
        for (int i = 0; i < K; i++) {
            if (i == p) continue;
            if (v[i] == -1) continue;

            if (v[i] & (1 << p)) v[i] ^= v[p];
        }
    }

    int x = tar;
    for (int i = K - 1; i >= 0; i--) {
        if (v[i] != -1 && (x & (1LL << i)) == 0) {
            //cout << "i:" << i << "\n";
            x ^= v[i];
        }
    }

    cout << x << "\n";
} 

/*
1
3 5
1 7 9
*/
 
signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        init ();
        solve();
    }
}  
```
