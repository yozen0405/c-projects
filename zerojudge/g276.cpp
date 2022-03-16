#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int x,y,s,t;
    bool alive;
}mp[505];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        cin>>mp[i].y>>mp[i].x>>mp[i].t>>mp[i].s;  //cin>>mp[i].x>>mp[i].y>>mp[i].s>>mp[i].t;
        mp[i].alive=1;
    }
    int now_alive=k,bomb[n][m],maze[n][m];
    memset(maze,0,sizeof(maze));
    while(now_alive){
        memset(bomb,0,sizeof(bomb));
        for(int p=0;p<k;p++){
            if(mp[p].alive==0) continue;
            int i=mp[p].x,j=mp[p].y;
            maze[j][i]=1;  //maze[i][j]=1; 
        }
        for(int p=0;p<k;p++){
            if(mp[p].alive==0) continue;
            int nx=mp[p].x+mp[p].s,ny=mp[p].y+mp[p].t;
            if(nx>=m or nx<0 or ny>=n or ny<0){
                now_alive--;
                mp[p].alive=0;
            }
            else if(maze[ny][nx]){
                now_alive--;
                mp[p].alive=0;
                bomb[ny][nx]=1;  //bomb[nx][ny]=1;
            }
            else{
                mp[p].x=nx;
                mp[p].y=ny;
            }

        }
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(bomb[i][j]) maze[i][j]=0;
                }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(maze[i][j]) ans++;
                }
        }
    cout<<ans;
}
