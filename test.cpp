#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0;
vector<int> G[1000000];
vector<int> ans;
int cnt[1000000],wei[1000000];
void rec(int u){
    int mx_num;
    if(G[u].empty()){
        cout<<u<<" ";
        return;
    } 
    mx_num=G[u][0];
    for(auto v:G[u]){
        if(cnt[v]>cnt[mx_num]) mx_num=v;
    }
    rec(mx_num);
}
void dfs(int u){
    for(auto v:G[u]){
        dfs(v);
        cnt[u]+=cnt[v];
    }
}
signed main(){
    cin>>n>>m;
    int u,l,r;
    for(int i=n;i<=2*n-1;i++){
        cin>>cnt[i];
    }
    for(int i=0;i<m;i++){
        cin>>wei[i];
    }
    for(int i=1;i<=n-1;i++){
        cin>>u>>l>>r;
        G[u].push_back(l);
        G[u].push_back(r);
    }
    for(int i=0;i<m;i++){
        dfs(1);
        rec(1);
        
    }
}
