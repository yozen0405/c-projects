#include <bits/stdc++.h>
#define N 1000000
#define int long long
using namespace std;
int n,c,arr[N],num[11],r_minus[11],ans=0; //num index starts from 0
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>c;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(auto u:arr) num[u]++;
    for(int i=1;i<=c;i++){
        if(num[i]==0){
            cout<<0;
            return 0;
        }
    } 
    for(int l=0;l<n;l++){
        if(l>0){
            num[arr[l-1]]-=1;
            if(num[arr[l-1]]<=0) break; 
        }
        for(int i=1;i<11;i++) r_minus[i]=0;
        for(int r=n-1;r>=l;r--){
            r_minus[arr[r]]++;
            if(num[arr[r]]-r_minus[arr[r]]<=0){
                ans++;
                break;
            } 
            else ans++;
            cout<<"r:"<<r<<"\n";
        }
        cout<<"l:"<<l<<",ans:"<<ans<<"\n";
    }
    cout<<ans;
}
