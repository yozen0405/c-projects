//memory limit: 512MB, time limit: 1.00s
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=0,cnt[1000000];
vector<int> G[1000000];
void dfs(int u){
    for(auto v:G[u]){
        dfs(v);
        cnt[u]+=cnt[v];
    }
    cnt[u]+=1;
}
signed main(){
    cin>>n;
    int u;
    for(int i=2;i<=n;i++){
        cin>>u;
        G[u].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<cnt[i]-1;
        if(i!=n) cout<<" ";
    }
}
