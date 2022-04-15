#include <bits/stdc++.h>
#define int long long
using namespace std;
int h,w;
char arr[3000][3000];
int dp[3000][3000][3];
const int mod=1e9+7;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>h>>w;
    for(int i=1;i<=w;i++){
        for(int j=1;j<=h;j++){
            cin>>arr[i][j];
        }
    }
    dp[1][1][0]=dp[1][1][1]=dp[1][1][2]=1;
    for(int i=1;i<=w;i++){
        for(int j=1;j<=h;j++){
            if(arr[i][j]=='.'){
                if(i!=1||j!=1){
                    dp[i][j][0]=(dp[i][j-1][0]+dp[i][j-1][1]+dp[i][j-1][2]+dp[i][j-1][0])%mod;
                    dp[i][j][1]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j][1])%mod;
                    dp[i][j][2]=(dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2]+dp[i-1][j-1][2])%mod;
                    //cout<<"i:"<<i<<",j:"<<j<<'\n';
                    //cout<<dp[i][j][0]<<","<<dp[i][j][1]<<","<<dp[i][j][2]<<"\n";
                }
            }
        }
    }
    cout<<dp[w][h-1][0]+dp[w-1][h-1][2]+dp[w-1][h][1];
}
