#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 5e4+5;

int solve(vector<int>& a,int b){
    int n=a.size()-1;
    vector<vector<int>> dp(n+1,vector<int>(2));
    for(int i=1;i<=b;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        dp[i][1]=a[i];
    }
    for(int i=b+1;i<=n;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        dp[i][1]=max(dp[i-b-1][1],dp[i-b-1][0])+a[i];
    }
    return max(dp[n][0],dp[n][1]);
}

signed main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<solve(a,k);
}
