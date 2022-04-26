#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int ans=0;
vector<int> G[100001];
bool not_root[100001];
int hei[100001];
void dfs(int u){
    for(auto v:G[u]){
        dfs(v);
        hei[u]=max(hei[u],hei[v]);
    }
    hei[u]+=1;
    ans+=hei[u]-1;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int u=1,k,v;u<=n;u++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>v;
            G[u].push_back(v);
            not_root[v]=true;
        }
    }
    int rt=1;
    while(not_root[rt]) rt++;
    dfs(rt);
    cout<<rt<<"\n"<<ans;
}
