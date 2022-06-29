#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 5e4+5;
vector<int> G[maxn];
int n,k;
int dp1[maxn][501],dp2[maxn][501];
//dp1[u][k] 在u這個點"的下面"距離k的點有幾個
//dp2[u][k] 在u這個點"的下面或上面"距離k的點有幾個

void dfs1(int u=1,int par=0){
    for(auto v:G[u]){
        if(v==par) continue;
        dfs1(v,u);
    } 
    dp1[u][0]=1; //base case
    for(int i=1;i<=k;i++){
        for(auto v:G[u]){
            if(v==par) continue;
            dp1[u][i]+=dp1[v][i-1];
        }
    }

}


void dfs2(int u=1,int par=0){
    for(int i=0;i<=k;i++){
        dp2[u][i]=dp1[u][i];
    }
    if(par!=0){
        dp2[u][1]+=1; //base case,距離1在上的的只有par一點
        for(int i=2;i<=k;i++){
            dp2[u][i]+=dp2[par][i-1]-dp1[u][i-2];
            //我只需要在加par上面的，但會多算到下面的，扣掉
        }
    }
    for(auto v:G[u]){
        if(v==par) continue;
        dfs2(v,u);
    } 
}

signed main(){
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1();
    dfs2();
    int ans=0;
    for(int i=1;i<=n;i++) ans+=dp2[i][k];
    cout<<ans/2; //ex: (1,2) 跟 (2,1) 算一種
}
