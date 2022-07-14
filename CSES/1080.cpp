#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f;
const int M = 1e9 + 7;
const int maxn = 501;
int C[maxn][maxn];
int dp[maxn][maxn];

signed main () {
    string s;
    cin >> s;
    int n = s.size();
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            C[i][j] %= M;
            // C i 取 j
        }
    }
    for (int i = 0; i + 1 <= n; i++) dp[i + 1][i] = 1;
    for (int len = 2; len <= n; len += 2) {
        for (int l = 0; l <= n; l++){
            int r = l + len - 1;
            for (int k = l + 1; k <= r; k += 2) {
                if (s[l] == s[k]) {
                    int sum = dp[l + 1][k - 1] * dp[k + 1][r];
                    sum %= M;
                    sum = sum * C[(r - l + 1) / 2][(k - l + 1) / 2];
                    sum %= M;
                    dp[l][r] = (dp[l][r] + sum + M) % M;
                }
            }
        }
    }
	cout << dp[0][n - 1] << '\n';
}
