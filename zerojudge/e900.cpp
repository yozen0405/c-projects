#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,a[100000],b[100000],sum,times,mi,dp[1001][13001];
const int INF=0x3f3f3f3f;

signed main(){
    while(cin>>n){
        times=INF;
        mi=INF;
        sum=0;
        memset(dp,INF,sizeof(dp));
        dp[0][0]=0;
        //dp(i, j) 表示前 i 項，陣列 A 的總和是 j，最少要換幾次
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i];
            sum+=a[i]+b[i];
            for(int j=1*i;j<=13*i;j++){
                if(j-a[i]>=0) dp[i][j]=dp[i-1][j-a[i]];
                if(j-b[i]>=0) dp[i][j]=min(dp[i][j],dp[i-1][j-b[i]]+1);
            }
        }
        //找AB最小差值
        for(int j=1*n;j<=13*n;j++){
            if(dp[n][j]<INF){
                //abs(B的卡牌總和-A的卡牌總和)=abs((全-A)-A)=abs(sum-j-j)
                if(abs(sum-j-j)<mi){
                    mi=abs(sum-j-j);
                    times=dp[n][j];
                }
                else if(abs(sum-j-j)==mi){
                    if(times>dp[n][j]){
                        times=dp[n][j];
                    }
                }
            }
                
        }   
        cout<<times<<"\n";
        
    }
}
