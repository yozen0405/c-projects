#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 5005;
int n, W, K;

signed main(){
    /*
    講師 k 人，代表總重量 W 最多只能是 W/k ， 價值是大家一起變 k 倍，所以出來再乘 k 就好
    */
    cin >> n >> W >> K;
    vector<int> w(n+1);
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    vector<int> dp(W+1,-INF);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = W; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    vector<int> mx(W+1);
    mx[0] = dp[0];
    for(int i = 1; i <= W; i++) mx[i] = max(dp[i], mx[i-1]);
    //query O(1)
    for(int k = 1; k <= K; k++){
        int m = W / k;
        cout << mx[m] * k << '\n';
    }
}
