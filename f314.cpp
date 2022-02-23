#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int dp[51][100001],arr[51][100001];
signed main(){
    cin>>m>>n; //m行n個
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++) cin>>arr[i][j];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            int maxi=-1e9;
            if(j!=1) maxi=max(dp[i][j-1]+arr[i][j],maxi);
            if(j!=n) maxi=max(dp[i][j+1]+arr[i][j],maxi); 
            if(i!=1) maxi=max(maxi,dp[i-1][j]+arr[i][j]);
        }
    cout<<dp[m][n];
}
