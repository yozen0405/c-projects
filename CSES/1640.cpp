#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,target;
int arr[1000000];
map<int,int> mp;
signed main(){
    cin>>n>>target;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
         mp[arr[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(mp[target-arr[i]]&&mp[target-arr[i]]!=i){
            cout<<i<<" "<<mp[target-arr[i]];
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
}
