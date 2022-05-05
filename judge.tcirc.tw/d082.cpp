#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int INF=0x3f3f3f3f;
int arr[31][31];
int dp[31][31][31][31];
int rec(int i1,int i2,int j1,int j2){
    if(i1==i2||j1==j2) return 0;
    if(dp[i1][i2][j1][j2]) return dp[i1][i2][j1][j2];
    dp[i1][i2][j1][j2]=1e18;
    int cnt0=0,cnt1=0;
    for(int i=i1;i<=i2;i++){
        if(arr[i][j1]==0) cnt0++;
        else cnt1++;
    } 
    dp[i1][i2][j1][j2]=min(dp[i1][i2][j1][j2],rec(i1,i2,j1+1,j2)+min(cnt0,cnt1));
    cnt0=0,cnt1=0;
    for(int i=i1;i<=i2;i++){
        if(arr[i][j2]==0) cnt0++;
        else cnt1++;
    } 
    dp[i1][i2][j1][j2]=min(dp[i1][i2][j1][j2],rec(i1,i2,j1,j2-1)+min(cnt0,cnt1));
    cnt0=0,cnt1=0;
    for(int j=j1;j<=j2;j++){
        if(arr[i1][j]==0) cnt0++;
        else cnt1++;
    } 
    dp[i1][i2][j1][j2]=min(dp[i1][i2][j1][j2],rec(i1+1,i2,j1,j2)+min(cnt0,cnt1));
    cnt0=0,cnt1=0;
    for(int j=j1;j<=j2;j++){
        if(arr[i2][j]==0) cnt0++;
        else cnt1++;
    } 
    dp[i1][i2][j1][j2]=min(dp[i1][i2][j1][j2],rec(i1,i2-1,j1,j2)+min(cnt0,cnt1));
    return dp[i1][i2][j1][j2];
    
}
signed main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<rec(0,n-1,0,m-1);
}
