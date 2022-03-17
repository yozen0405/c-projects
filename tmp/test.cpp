#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
int arr[1000000];
signed main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=0,r=0,cnt=0;
    while(l!=n){
        map<int,int> mp;
        r=l;
        cnt=0;
        while(cnt<=k&&r<n){
            if(!mp[arr[r]]) cnt++;
            mp[arr[r]]++;
            r++;
            cout<<"r:"<<r<<",cnt:"<<cnt<<"\n";
        }
        cout<<l<<","<<r<<"\n";
        ans+=r-l;
        l++;
    }
    cout<<ans;
}
