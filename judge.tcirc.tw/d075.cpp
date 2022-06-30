#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s;
int dp[1000000];
signed main(){
    cin>>n>>m>>s;
    vector<int> w(n);
    int tmp=0;
    for(int i=0;i<n;i++){
        cin>>w[i];
        tmp+=w[i];
    }
    if(tmp+s<=m) cout<<"0",exit(0);
    int tot=m-s;
    for(int i=0;i<n;i++){
        for(int j=tot;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
        }
    }
    cout<<tmp-dp[tot]<<"\n";
}
