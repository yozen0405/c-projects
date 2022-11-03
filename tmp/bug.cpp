#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int N, M, K; cin >> N >> M >> K;
    string S, T; cin >> S >> T, T = "?" + T, ++M;
    
    vector<vector<int>> pre(N+1, vector<int>(26, -1));
    for (int i = 1; i <= N; ++i) {
        pre[i] = pre[i-1];
        pre[i][S[i-1] - 'a'] = i-1;
    }
    
    vector<vector<int>> nxt(M+1, vector<int>(26, M));
    for (int i = M-2; i >= 0; --i) {
        nxt[i] = nxt[i+1];
        nxt[i][T[i+1] - 'a'] = i+1;
    }
    
    vector<vector<int>> dp(N+1, vector<int>(K+1, M));
    dp[0][0] = 0, dp[0][1] = nxt[0][S[0] - 'a'];
    for (int i = 1; i < N; ++i) {
        dp[i][0] = 0;
        for (int j = 1; j <= K; ++j) {
            dp[i][j] = min(
                dp[i-1][j],
                nxt[dp[i-1][j-1]][S[i] - 'a']
            );
        }
    }
    
    for (int len = K; len >= 1; --len) {
        if (dp[N-1][len] == M) continue;
        
        int pos_t = dp[N-1][len], pos_s = pre[N][T[pos_t] - 'a'];
        string ans(len, '?');
        
        ans[len-1] = S[pos_s];
        for (int i = len-1; i >= 1; --i) {
            pos_t = dp[pos_s-1][i];
            pos_s = pre[pos_s][T[pos_t] - 'a'];
            ans[i-1] = S[pos_s];
        }
        
        cout << len << "\n" << ans << "\n";
        return 0;
    }
    cout << 0 << "\n" << "\n";
    
    return 0;
}
