#include <bits/stdc++.h>
#define int long long
using namespace std;
int L,N,arr[10000],dp[10000][10000];
int rec(int l, int r){
    cout<<l<<r<<'\n';
    if(r-l==1) return 0;
    for(int k=l+1;k<r;k++){
        dp[l][r]=min(rec(l,k)+rec(k,r)+arr[r]-arr[l],dp[l][r]);
    }
    return dp[l][r];
}
signed main(){
    for(int i=0;i<3;i++){
        cin>>L>>N;
        arr[0]=0;
        for(int j=1;j<=N;j++){
            cin>>arr[i];
        }
        arr[N+1]=L;
        for(int j=0;j<5000;j++)
            for(int k=0;k<5000;k++) dp[j][k]=1e9;
        cout<<rec(0,N+1)<<'\n';
    }
}
