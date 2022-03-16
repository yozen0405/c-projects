#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=0,dp[1000000][2];
vector<int> G[1000000];
void dfs(int u){
    for(auto v:G[u]){
        dfs(v);
        dp[u][0]+=max(dp[v][0],dp[v][1]);
        dp[u][1]+=dp[v][0];
    }
}
signed main(){
    cin>>n;
    int r,p;
    for(int i=1;i<=n;i++){
        if(i==1)
            cin>>r;
        else{
            cin>>p>>r;
            G[p].push_back(i);
        }
        dp[i][0]=0;
        dp[i][1]=r;
    }
    dfs(1);
    cout<<max(dp[1][0],dp[1][1])<<"\n";
}
