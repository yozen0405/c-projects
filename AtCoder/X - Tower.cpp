#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 1e9+7;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5; 
vector<int> G[maxn];
int n;

struct node{
    int w,s,v;
};

int cmp(node a,node b){
    return a.w+a.s<b.w+b.s;
}

signed main(){
    cin >> n;
    vector<node> a(n+1);
    int mx=-INF;
    for(int i=1;i<=n;i++){
        cin>>a[i].w>>a[i].s>>a[i].v;
    }
    sort(a.begin()+1,a.end(),cmp);
    mx=a.back().w+a.back().s;
    vector<vector<int>> dp(n+1,vector<int>(mx+1,-INF));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=a[i].s+a[i].w;j>=0;j--){
            if(j<a[i].w) dp[i][j]=dp[i-1][j];
            if(j<a[i].w) continue;
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i].w]+a[i].v);
        }
    }
    int mxx=-INF;
    for(int i=0;i<=mx;i++) mxx=max(mxx,dp[n][i]);
    cout<<mxx;
}
