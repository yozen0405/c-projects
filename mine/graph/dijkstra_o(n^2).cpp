#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int INF=0x3f3f3f3f;
int dis[100000];
int vis[100000];
struct edge{
    int v,w;
};
vector<edge> G[100000];
int find(){
    int mi=INF,idx;
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        if(dis[i]<mi){
            mi=dis[i];
            idx=i;
        }
    }
    return idx;
}
void dijkstra(int source){
    fill(dis,dis+n,INF);
    fill(vis,vis+n,false);
    dis[source]=0;
    for(int i=0;i<n;i++){
        int u=find();
        vis[u]=true;
        for(auto [v,w]:G[u]){
            if(vis[v]) continue;
            dis[v]=min(dis[v],dis[u]+w);
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0,u,v,w;i<m;i++){
        cin>>u>>v>>w;
        u--,v--;
        G[u].push_back({v,w});
    }
    dijkstra(0);
}
