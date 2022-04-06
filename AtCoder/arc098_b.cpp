//https://atcoder.jp/contests/abc098/tasks/arc098_b
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int pref[1000000],xr[1000000];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int num;
    for(int i=1;i<=n;i++){
        cin>>num;
        pref[i]=pref[i-1]+num;
        xr[i]=xr[i-1]^num;
    }
    int ans=0,l=1,tmp;
    for(int r=1;r<=n;r++){
        tmp=xr[r]^xr[l-1];
        while((pref[r]-pref[l-1])!=tmp){
            l++;
            tmp=xr[r]^xr[l-1];
        } 
        ans+=r-l+1;
    }
    cout<<ans;
}
