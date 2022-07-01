#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 1e9+7;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5; 
vector<int> G[maxn];
int n;
int dp[maxn][2]; //0-white,1-black
//dp[u][0/1] 在u這個點圖白/黑色，u的下面(subtree)圖色的方法數

void dfs(int u=1,int par=0){
    dp[u][1]=dp[u][0]=1;
    for(auto v:G[u]){
        if(v==par) continue;
        dfs(v,u);
        dp[u][0]*=(dp[v][0]+dp[v][1]);
        dp[u][0] %= M;
        dp[u][1]*=dp[v][0];
        dp[u][1] %= M;
    }
}

signed main(){
    cin >> n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs();
    cout<<(dp[1][0]+dp[1][1])%M;
}
