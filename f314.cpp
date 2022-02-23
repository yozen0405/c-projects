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
            if(i==1&&j!=1) dp[i][j]=max(arr[i][j],dp[i][j-1]+arr[i][j]);
            else if(j==1&&i==1) dp[i][j]=arr[i][j];
            else if(j==1) dp[i][j]=dp[i-1][j]+arr[i][j];
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j])+arr[i][j];
            cout<<"i:"<<i<<",j:"<<j<<",ans:"<<dp[i][j]<<"\n";
        }
    int maxi=-1e9;
    for(int i=1;i<=m;i++)
        for(int j=n;j>0;j--){
            if(i==1) dp[i][j]=max(dp[i][j],dp[i][j+1]+arr[i][j]);
            else if(j==n&&i!=1) dp[i][j]=max(dp[i][j],dp[i-1][j]+arr[i][j]);
            else dp[i][j]=max({dp[i][j],dp[i][j+1]+arr[i][j],dp[i-1][j]+arr[i][j]});
            
            maxi=max(maxi,dp[i][j]);
        }
    cout<<maxi;
}
