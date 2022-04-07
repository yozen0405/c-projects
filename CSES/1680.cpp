#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int din[1000000],dp[1000000],vis[1000000];
pair<int,int> mx;
vector<int> G[1000000];
vector<int> T(1000000);
void dfs(int u, int par=-1){
  vis[u] = true;
    for(int v : G[u])
        if(v != par && !vis[v])
            dfs(v, u);
}
void solve(){
    dfs(0);
    if(!vis[n-1]){
      cout<<"IMPOSSIBLE"; //bug
      exit(0);
    }
    for(int i=0;i<n;i++){
      for(auto v:G[i]){
        din[v]++;
      }
    }
    queue<int> q;
    for(int i=1;i<n;i++) dp[i]=-1;
    for(int i=0;i<n;i++){
      if(din[i]==0){
        q.push(i);
      } 
    }
    int u,cnt=0;
    dp[0]=1;
    while(!q.empty()){
      u=q.front();
      q.pop();
      cnt++;
      for(auto v:G[u]){
        if(dp[u]!=-1&&dp[u]+1>dp[v]){ //dp[u]!=-1 bug
          T[v]=u;
          dp[v]=dp[u]+1;
        }
        din[v]--;
        if(!din[v]) q.push(v); 
      }
    }
    cout<<dp[n-1]<<"\n";
    vector<int> ans(dp[n-1]);
    int v=n-1;
    for(int i=0;i<ans.size();i++){
      ans[i]=v;
      v=T[v];
    }
    for(int i=ans.size()-1;i>=0;i--){
      cout<<ans[i]+1<<" ";
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++){
      cin>>u>>v;
      u--,v--;
      G[u].push_back(v);
    }
    solve();
}
