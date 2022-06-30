#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;

int maxProfit(int d, vector<int>& prices) {
    const int INF=0x3f3f3f3f;
    int n=prices.size();
    if(2*d>n) d=n>>1;
    d*=2;
    vector<vector<int>> dp(d+1,vector<int>(n+1));
    vector<vector<int>> mx(d+1,vector<int>(n+1,-INF));
    for(int i=0;i<=n;i++) mx[0][i]=0;
    int ans=0;
    for(int k=1;k<=d;k++){
        for(int i=1;i<=n;i++){
            dp[k][i]=-INF;
            if(k>i) continue;
            dp[k][i]=max(dp[k][i],mx[k-1][i-1]+((k&1) ? -1:1)*prices[i-1]);
            mx[k][i]=max(mx[k][i-1],dp[k][i]); //k~i
            ans=max(ans,dp[k][i]);
        }
    }
    return ans;
}
signed main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<maxProfit(k,a);
}
