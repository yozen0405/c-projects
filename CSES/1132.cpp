#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int maxn=2e5+5;
const int INF=0x3f3f3f3f;
int n;
int fir[maxn],sec[maxn],ans[maxn];
vector<int> G[maxn];
 
//計算最大和其次的深度
void dfs1(int u=1,int par=0){
    for(auto v:G[u]){
        if(v==par) continue;
        dfs1(v,u);
        if(fir[v]+1>fir[u]){
            sec[u]=fir[u];
            fir[u]=fir[v]+1;
        }
        else if(fir[v]+1>sec[u]){
            sec[u]=fir[v]+1;
        }
    }
}
 
//計算最遠distance

void dfs2(int u=1,int par=0,int p=0){
    //p為從可能par更上面的點連par再到u的max len
    ans[u]=max(p,fir[u]);//可能在自己的subtree內(fir[u])或subtree外(p)
    for(auto v:G[u]){
        if(v==par) continue;
        if(fir[v]+1==fir[u]) dfs2(v,u,max(sec[u],p)+1); 
        //在u的max len中，那不包含v subtree的可能可能是u的第二大的v(叫做v2)，也有可能往上接(往par和u甚至更上去)
        else dfs2(v,u,ans[u]+1);
        //在u的max len外，直接接u(u的可能性max在28行就算過了)
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
