#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
int cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first) return a.second<b.second;
    return a.first>a.first;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<int,int>> vec(n);
        vector<int> cnt(n);
        int l,r;
        for(int i=0;i<n;i++){
            cin>>vec[i].first>>vec[i].second;
        }
        sort(vec.begin(),vec.end(),cmp);
        int mx=-1e9;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(vec[i].second>=vec[j].first){
                    cnt[i]++;cnt[j]++;
                }
            }
            mx=max(mx,cnt[i]);
        }
        cout<<n-(mx+1)<<"\n";

    }
}
