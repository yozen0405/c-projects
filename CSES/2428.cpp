//https://cses.fi/problemset/task/2428
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
    int l=0,r=-1,cnt=0;
    while(l!=n){
        if(l!=0&&mp[arr[l-1]]){
            if(mp[arr[l-1]]==1)
              cnt--;
            mp[arr[l-1]]--;
        }
        while(cnt<=k&&r<n-1){
            r++;
            if(!mp[arr[r]]) cnt++;
            mp[arr[r]]++;
        }
        if(cnt>k){
            mp[arr[r]]--;
            r--;
            cnt--;
        }
        ans+=r-l+1;
        l++;
    }
    cout<<ans;
}
