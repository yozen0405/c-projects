//https://codeforces.com/problemset/problem/1538/C
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,t,ans=0;
signed main(){
    cin>>t;
    while(t--){
        ans=0;
        int l,r;
        cin>>n>>l>>r;
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        sort(vec.begin(),vec.end());
        for(int i=n-1;i>=1;i--){
            if(vec[i]>r) continue;
            int init;
            if(vec[i]>l) init=0;
            else{
                auto tmp_init=lower_bound(vec.begin(),vec.begin()+i-1,l-vec[i]);
                init = tmp_init-vec.begin();
                if(*tmp_init+vec[i]<l) continue;
            } 
            auto tmp=upper_bound(vec.begin(),vec.begin()+i-1,r-vec[i]);
            int pos;
            if(*tmp+vec[i]<=r) pos=i;
            else pos=tmp-vec.begin();
            //cout<<init<<","<<pos<<"\n";
            ans+=pos-init;
        }
        cout<<ans<<"\n";
    }
}
