#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,tmp;
int vis[1001][1001];
char arr[1001][1001];
int d[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
void dfs(int i,int j){
  for(auto [u,v]:d){
    if(i+u>=n||i+u<0||j+v<0||j+v>=m) continue;
    if(arr[i+u][j+v]=='#') continue;
    if(vis[i+u][j+v]) continue;
    vis[i+u][j+v]=1;
    dfs(i+u,j+v);
    
  } 
}
signed main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++) cin>>arr[i][j];
    int ans=0;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++){
        if(arr[i][j]=='.'&&!vis[i][j]){
            dfs(i,j);
            ans++;
        } 
      }
    cout<<ans;
}
