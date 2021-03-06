// https://codeforces.com/problemset/problem/987/D
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
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1;i<=k;i++){
        vector<int> vis(n+1); //vector<int> vis(n)
        queue<int> q;
        for(int j=1;j<=n;j++){
            if(arr[j]==i)
            {
                vis[j]=1;
                q.push(j);
            }
             
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:G[u]){
                if(!vis[v]){ //if(vis[v])
                    dis[v][i]=dis[u][i]+1;
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        sort(dis[i]+1,dis[i]+k+1); //sort(dis[i]+1,dis[i]+k)
        ans=0;
        for(int j=1;j<=s;j++){
            ans+=dis[i][j];
        }
        cout<<ans<<"\n";
    }
}
