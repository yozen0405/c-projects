#include <bits/stdc++.h>
#define int long long
#define mk make_pair
#define pii pair<int,int>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int n;
int dp[maxn][2];
map<int,int> mp;

signed main(){
    cin >> n;
    int num;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> num;
        mp[num]++;
        mx = max(mx, num);
    }
    int prev = -1,prev0 = 0, prev1 = 0;
    for(auto [u,cnt] : mp){
        dp[u][0] = max(prev0, prev1);
        dp[u][1] = ((u - prev == 1) ? prev0 : max(prev0,prev1)) + cnt*u;
        prev0 = dp[u][0];
        prev1 = dp[u][1];
        prev = u;
    }
    cout << max(dp[mx][0], dp[mx][1]);
}   
