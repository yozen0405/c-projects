#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100000],b[100000],sum,times,mi,dp[2000][14000];
const int INF=0x3f3f3f3f;
signed main(){
    while(cin>>n){
        times=1e9;
        mi=1e9;
        sum=0;
        for(int i=0;i<2000;i++)
            for(int j=1;j<14000;j++) dp[i][j]=INF; 
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i];
            sum+=a[i]+b[i];
            for(int j=1*i;j<=13*i;j++){
                if(j-a[i]>=0) dp[i][j]=dp[i-1][j-a[i]];
                if(j-b[i]>=0) dp[i][j]=min(dp[i-1][j],dp[i-1][j-b[i]]+1);
            }
        }
        cout<<"y\n";
        int ii,jj;
        for(int j=1*n;j<=13*n;j++){
            if(dp[n][j]<INF){
                if(abs(sum-j-j)<mi){
                    mi=abs(sum-j-j);
                    times=dp[n][j];
                    ii=n;
                    jj=j;
                    cout<<sum<<","<<ii<<","<<jj<<","<<mi<<","<<times<<"\n";
                }
                else if(abs(sum-j-j)==mi){
                    if(times>dp[n][j]){
                        times=dp[n][j];
                        ii=n;
                        jj=j;
                        cout<<sum<<","<<ii<<","<<jj<<","<<mi<<","<<times<<"\n";
                    }
                }
            }
                
        }
        cout<<dp[n][37]<<"\n";
        
    }
}
