#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=0,h[1000000],dp[1000000];
vector<int> G[1000000];
void dfs(int u, int parent){
    int maxi=0,sec=0;
    for(auto v:G[u]){
        if(v==parent) continue;
        dfs(v, u);
        dp[u]=max(dp[u],dp[v]);
        if(h[v]>=maxi){
            sec=maxi;
            maxi=h[v];
        }
        else if(h[v]>=sec)
            sec=h[v];
    }
    h[u]=maxi+1;
    dp[u]=max(dp[u],maxi+sec+1);
}
signed main(){
    cin>>n;
    int u,v;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 1);
    cout<<dp[1]-1<<"\n";
}
