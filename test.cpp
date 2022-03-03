#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=0;
vector<int> G[1000000];
int cnt[1000000],hei[1000000],is_root[1000000];
void dfs(int u,int p){
    cnt[u]=cnt[p]+1;
    for(auto v:G[u]){
        if(v==p) continue;
        dfs(v, u);
    }
}
signed main(){
    cin>>n;
    int u,v;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, 0);
    int mx=0;
    for(int i=0;i<n;i++){
        if(cnt[i]>cnt[mx]) mx=i;
    }
    for(int i=0;i<n;i++){
        cnt[i]=0;
    }
    dfs(mx, mx);
    for(int i=0;i<n;i++){
        if(cnt[i]>cnt[mx]) mx=i;
    }
    cout<<cnt[mx]<<"\n";
}
