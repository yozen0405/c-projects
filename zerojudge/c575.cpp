#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
signed main(){
    cin>>n>>k;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    int l=1,r=1e18;
    while(l<r-1){
        int mid=(l+r)/2;
        int cnt=0;
        auto it=upper_bound(vec.begin(),vec.end(),0);
        while(true){
            it = upper_bound(vec.begin(),vec.end(),*it+mid);
            cnt++;
            if(it==vec.end()){
                break;
            }
        }
        if(cnt>k) l=mid;
        else r=mid;
    }
    cout<<r;
    
}
