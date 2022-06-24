#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int maxn=2e5+5;
const int INF=0x3f3f3f3f;
int n;
int sz[maxn],ans[maxn];
vector<int> G[maxn];
 

//計算subtree大小
void dfs1(int u=1,int par=0,int dep=0){
    ans[1]+=dep;
    sz[u]=1;
    for(auto v:G[u]){
        if(v==par) continue;
        dfs1(v,u,dep+1);
        sz[u]+=sz[v];
    }
}
 
//計算與各點間的距離
void dfs2(int u=1,int par=0){
    for(auto v:G[u]){
        if(v==par) continue;
        ans[v]=ans[u]+n-2*sz[v];
        //如果說我已經知道u與各點之間的距離，那對於v來說就是將v的subtree裡面的node的深度全部-1，subtree外的全部+1
        dfs2(v,u);
    }
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0,u,v;i<n-1;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1();
    dfs2();
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
 
}
