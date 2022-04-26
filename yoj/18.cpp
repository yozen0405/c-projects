// memory limit: 512MB, time limit: 1.00s
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int> G[1000000];
int root=99999;
int hei[1000000],dp[1000000],ans;
void dfs(int u,int par){
    int mx1=0,mx2=0;
    for(auto v:G[u]){
        if(v==par) continue;
        dfs(v,u);
        dp[u]=max(dp[v],dp[u]);
        if(hei[v]>hei[mx1]){
            mx2=mx1;
            mx1=v;
        } 
        else if(hei[v]>hei[mx2]) mx2=v; 
    }
    hei[u]=1+hei[mx1];
    dp[u]=max(dp[u],hei[mx1]+hei[mx2]+1);
}
signed main(){
    cin>>n;
    int u,v;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1);
    cout<<dp[1]-1<<"\n";
}
