#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
int arr[1000000];
map<int,int> mp;
signed main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=0,r=0,cnt=0;
    while(cnt<=k&&r<n){
            if(!mp[arr[r]]) cnt++;
            mp[arr[r]]++;
            r++;
            cout<<"r:"<<r<<",cnt:"<<cnt<<"\n";
    }
    r--;
    if(cnt>k){
            mp[r]--;
            r--;
            cnt--;
    }
     cout<<l<<","<<r<<",cnt:"<<cnt<<"\n";
    while(l!=n-1){
        if(mp[l]==1){
            cnt--;
            mp[l]=0;
        }
        l++;
        while(cnt<=k&&r<n){
            if(!mp[arr[r]]) cnt++;
            mp[arr[r]]++;
            r++;
            cout<<"r:"<<r<<",cnt:"<<cnt<<"\n";
        }
        r--;
        if(cnt>k){
            mp[r]--;
            r--;
            cnt--;
        } 
        
       cout<<l<<","<<r<<",cnt:"<<cnt<<"\n";
        ans+=r-l+1;
    }
    cout<<ans;
}
