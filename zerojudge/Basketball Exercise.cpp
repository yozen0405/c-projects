//https://codeforces.com/problemset/problem/1195/C
#include <iostream>
#include <algorithm>
#define int long long
#define N 100001
using namespace std;
int n, arr[N][2], dp[N][2], n_size = 0, n_front, ans;
signed main()
{
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> arr[i][0];
    }
    for (int i = 1;i <= n;i++) {
        cin >> arr[i][1];
    }
    dp[1][0] = arr[1][0];
    dp[1][1] = arr[1][1];
    for (int i = 2;i <= n;i++) {
        dp[i][0] = max({ dp[i - 2][0], dp[i - 2][1], dp[i - 1][1] }) + arr[i][0];
        dp[i][1] = max({ dp[i - 2][0], dp[i - 2][1], dp[i - 1][0] }) + arr[i][1];
    }
    for (int i = 1;i <= n;i++) {
        ans = max({ ans, dp[i][0], dp[i][1] });
    }
    cout << ans;
}
