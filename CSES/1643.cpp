//https://cses.fi/problemset/task/1643/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int arr[1000000],dp[1000000];
signed main(){
    cin>>n;
    int mx=-1e18;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        dp[i]=max(arr[i],dp[i-1]+arr[i]);
        mx=max(dp[i],mx);
    }
    cout<<mx;
}
