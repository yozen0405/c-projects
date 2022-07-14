#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f;
const int M = 1e9 + 7;
vector<int> num;
int n, k;
int dp[101][5][2];

int dfs(int pos, int cnt, bool tight) {
    if (cnt > k) return 0;
    if (dp[pos][cnt][tight]) return dp[pos][cnt][tight];
    if(pos == n) return (cnt == k);
    int up = (tight ? num[pos] : 9);
    int ans = 0;
    for (int i = 0; i <= up; i++) {
        ans += dfs(pos + 1, cnt + (i != 0), tight && (i == num[pos]));
    } 
    return dp[pos][cnt][tight] = ans;
}

signed main() {
    string s;
    cin >> s;
    cin >> k;
    for (int i = 0; i < s.size(); i++) {
        num.push_back(s[i] - '0');
    }
    n = s.size();
    cout << dfs(0, 0, 1);
}
