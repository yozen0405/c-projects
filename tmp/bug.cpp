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
    if(w>=1&&h>=2&&arr[1][2]=='.')
        dp[1][2][0]=1;
    if(w>=2&&h>=1&&arr[2][1]=='.')
        dp[2][1][1]=1;
    if(w>=2&&h>=2&&arr[2][2]=='.')
        dp[2][2][2]=1;
    for(int i=1;i<=w;i++){
        for(int j=1;j<=h;j++){
            if(arr[i][j]=='.'){
                if((i==1&&j==2)||(i==2&&j==1)){
                    //cout<<"i:"<<i<<",j:"<<j<<'\n';
                    //cout<<dp[i][j][0]<<","<<dp[i][j][1]<<","<<dp[i][j][2]<<"\n";
                     continue;
                }
                else if((i==2&&j==2)){
                    dp[i][j][0]=(dp[i][j-1][0]+dp[i][j-1][1]+dp[i][j-1][2]+dp[i][j-1][0])%mod;
                    dp[i][j][1]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j][1])%mod;
                }
                else{
                    dp[i][j][0]=(dp[i][j-1][0]+dp[i][j-1][1]+dp[i][j-1][2]+dp[i][j-1][0])%mod;
                    dp[i][j][1]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j][1])%mod;
                    dp[i][j][2]=(dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2]+dp[i-1][j-1][2])%mod;
                    //cout<<"i:"<<i<<",j:"<<j<<'\n';
                    //cout<<dp[i][j][0]<<","<<dp[i][j][1]<<","<<dp[i][j][2]<<"\n";
                }
            }
        }
    }
    cout<<(dp[w][h][0]+dp[w][h][1]+dp[w][h][2])%mod;
}
