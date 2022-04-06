#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,s,arr[1000000];
int dis[100001][305];
vector<int> G[1000000];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k>>s;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }    
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=k;i++){
        vector<int> vis(n);
        queue<int> q;
        for(int j=1;j<=n;j++){
            if(arr[j]==k) vis[j]=1;
            q.push(j);
        }
        //bfs
        while(!q.empty()){
            
        }
    }
}
