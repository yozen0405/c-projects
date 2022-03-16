#include <bits/stdc++.h>
#define N 50000
using namespace std;
int n,parent[N],visited[N],ans;
int rec(int num,int root){
    visited[num]=1;
    if(num==root){
        ans++;
        return 0;
    }
    rec(parent[num], root);
}
signed main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>parent[i];
    }
    for(int i=0;i<n;i++){
        if(visited[i]) continue;
        rec(parent[i],i);
    }
    cout<<ans;
}
