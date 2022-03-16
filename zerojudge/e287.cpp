#include <bits/stdc++.h>
#define int long long
#define N 101
using namespace std;
int n,m,arr[N][N],d[4][2]={{1,0},{-1,0},{0,1},{0,-1}},total=0;
bool visited[N][N];
signed main()
{
    //input
    cin>>n>>m;
    int mini_i,mini_j,mini=1e9;
    for(int j=0;j<n;j++)
        for(int i=0;i<m;i++){
            cin>>arr[j][i];
            if(arr[j][i]<mini){
                mini_i=i;
                mini_j=j;
                mini=arr[j][i];
            }
    }
    visited[mini_j][mini_i]=1;
    total+=mini;
    //solve
    int i=mini_i,j=mini_j;
    while(true){
            int tmp_i,tmp_j,minn=1e9;
            for(auto [u,v]:d){
                int nx=j+u,my=i+v;
                if(nx>=n||nx<0||my>=m||my<0) continue;
                if(visited[nx][my]) continue;
                if(arr[nx][my]<minn){
                    tmp_i=my;
                    tmp_j=nx;
                    minn=arr[nx][my];
                }
            }
            if(minn==1e9) break;
            i=tmp_i,j=tmp_j;
            visited[j][i]=1;
            total+=arr[j][i];
        }
        cout<<total;
}
