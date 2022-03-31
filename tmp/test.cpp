#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string arr[1000001];
vector<int> G[100001];
void dfs(int u){
    cout<<arr[u];
    for(auto v:G[u]){
        dfs(v);
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int u,v;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        G[u].push_back(v);
        if(i==n-1) dfs(u);
    }
    
}
