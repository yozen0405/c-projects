#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
using namespace std;

int L, R, n;

int cnt (int start, int num) {
    return (start + start + 2 * (num - 1)) * num / 2;
}

void solve() {  
    cin >> L >> R;
    bool flg = 0;
    if (R > L) {
        flg = 1;
        swap(L, R);
    } 
    int xl = 0, xr = 2e9 + 5;
    while (xl < xr - 1) { // L >= R
        int m = (xl + xr) >> 1;
        if (L - m * (m + 1) / 2 < R) {
            xr = m;
        }
        else {
            xl = m;
        }
    }
    int ans1 = xl;
    L -= xl * (xl + 1) / 2;
    int lb = 0, rb = 2e9 + 5;
    if (L == R) flg = 0;
    while (lb < rb - 1) {
        int m = (lb + rb) >> 1;
        // 幾輪
        if (L - cnt(xl + 1, m) < 0) {
            rb = m;
        }
        else { // L - cnt >= 0
            lb = m;
        }
    }
    int ans2 = L - cnt(xl + 1, lb);
    ans1 += lb;
    lb = 0, rb = 2e9 + 5;
    while (lb < rb - 1) {
        int m = (lb + rb) >> 1;
        // 幾輪
        if (R - cnt(xl + 2, m) < 0) {
            rb = m;
        }
        else { // L - cnt >= 0
            lb = m;
        }
    }
    int ans3 = R - cnt(xl + 2, lb);
    ans1 += lb;
    if(!flg) cout << ans1 << " " << ans2 << " " << ans3 << "\n";
    else cout << ans1 << " " << ans3 << " " << ans2 << "\n";
}

signed main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
