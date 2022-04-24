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
void dijkstra(int source){
    fill(dis,dis+n,INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,source});
    while (pq.size())
    {
        int d=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(dis[u]!=INF) continue;
        dis[u]=d;
        for(int j=0;j<G[u].size();j++){
            int v=G[u][j].v;
            int w=G[u][j].w;
            pq.push({d+w,v});
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
