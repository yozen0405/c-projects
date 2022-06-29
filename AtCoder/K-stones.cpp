#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e2+5;
int n;

signed main(){
    int k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> dp(k+1);
    //dp[k] 在目前剩k個石頭的情況下對於那輪的玩家來說有沒有可能贏
    for(int i=1;i<=k;i++){
        for(int ele:a){
            if(i-ele>=0&&(!dp[i-ele])){
                dp[i]=1;
                break;
            }
        }
    }
    cout<<(dp[k] ? "First":"Second");
}
