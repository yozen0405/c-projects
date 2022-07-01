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
    //greedy
    //s1-w2<s2-w1 (代表第1個東西還能放的重量比第2個東西還多)
    //因為等等要做背包問題，我另新的要疊在下面，阿疊在下面的能放的重量一定要比較大，所以先從小的到大的
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
    //dp[i][j] 看前 i 個物品，整個重量為 j 的最大 value
    //dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i].w]+a[i].v); i 疊在之前的那疊 (j-a[i].w) 的最下面
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=a[i].s+a[i].w;j>=0;j--){
            if(j<a[i].w) dp[i][j]=dp[i-1][j]; 
            if(j<a[i].w) continue;
            //真正有可能可以把第 i 個疊在目前最下面的只有在目前 s[i] 還沒被消耗完的時候
            // j-a[i].w 最大只有可能是 a[i].s , 成功做到下面的 s[i] 要達於等於上面的重量總和
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i].w]+a[i].v);
        }
    }
    int mxx=-INF;
    for(int i=0;i<=mx;i++) mxx=max(mxx,dp[n][i]);
    cout<<mxx;
}
