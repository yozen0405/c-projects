```cpp
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
const int maxn = 1e4 + 5;
const int maxm = 27;
const int M = 1e9 + 7;

int n;
string s;
int dp[maxn][maxm];
int dis[maxm][maxm];
vector<int> G[maxn];
vector<vector<char>> A = {{'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'},
                          {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'},
                          {'Z', 'X', 'C', 'V', 'B', 'N', 'M'}};

int check (int i, int row) {
    if (0 > row || row >= 3) return 0;
    if (0 <= i && i < A[row].size()) return 1;
    return 0;
}

void add_edge (int i, int row1, int j, int row2) {
    cout << "i:" << i << ",row1:" << row1 << ",j:" << j << ",row2:" << row2 << "\n";
    if (check (i, row1) == 0 || check (j, row2) == 0) return;
    cout << "fk\n";
    dis[A[row1][i] - 'a' + 1][A[row2][j] - 'a' + 1] = 1;
    dis[A[row2][j] - 'a' + 1][A[row1][i] - 'a' + 1] = 1;
    cout << "y\n";
}

void build () {
    cout << "hi\n";
    for (int i = 1; i <= 26; i++) {
            for (int j = 1; j <= 26; j++) {
                dis[i][j] = INF;
            }
    }
    int row = -1;
    for (auto vec : A) {
        row++;
        int i = 0;
        for (auto ele : vec) {
            add_edge (i, row, i - 1, row + 1);
            cout << "yes\n";
            add_edge (i, row, i, row + 1);
            cout << "yes\n";
            add_edge (i, row, i, row - 1);
            cout << "yes\n";
            add_edge (i, row, i + 1, row - 1);
            cout << "yes\n";
            add_edge (i, row, i + 1, row);
            cout << "yes\n";
            add_edge (i, row, i - 1, row);
            cout << "yes\n";
            i++;
            cout << ele << "\n";
        }
    }

    cout << "di\n";
    for (int k = 1; k <= 26; k++) {
        for (int i = 1; i <= 26; i++) {
            for (int j = 1; j <= 26; j++) {
                if (dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

void init () {
    //cin >> n >> s;
}

void solve () {
    build ();
} 
 
signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        init();
        solve();
    }
}
```
