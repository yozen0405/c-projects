//https://cses.fi/problemset/task/1131/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=0,cnt[1000000];
vector<int> G[1000000];
void dfs(int u, int parent){
    cnt[u]=cnt[parent]+1;
    for(auto v:G[u]){
        if(v==parent) continue;
        dfs(v, u);
    }
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
    int max_=1;
    for(int i=1;i<=n;i++){
        if(cnt[i]>cnt[max_]) max_=i;
    }
    for(int i=1;i<=n;i++){
        cnt[i]=0;
    }
    dfs(max_,max_);
    for(int i=1;i<=n;i++){
        if(cnt[i]>cnt[max_]) max_=i;
    }
    cout<<cnt[max_]-1<<"\n";
}
