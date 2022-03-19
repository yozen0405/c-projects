#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=0;
vector<int> G[1000000];
int cnt[1000000],hei[1000000];
void dfs(int u){
    for(auto v:G[u]){
        dfs(v);
        hei[u]=max(hei[u],hei[v]+1);
    }
}
signed main(){
    cin>>n;
    int v,k;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>v;
            G[i].push_back(v);
            cnt[v]=1;
        }
    }
    int root;
    for(int i=1;i<=n;i++){
        if(!cnt[i]){
            root=i;
            break;
        }
    }
    dfs(root);
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=hei[i];
    cout<<root<<"\n"<<sum;
}
