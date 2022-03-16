#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,target;
int arr[1000000];
map<int,int> mp;
signed main(){
    cin>>n;
    int k=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(!mp[arr[i]]){
            k++;
            mp[arr[i]]=1;
        }
        
    }
    cout<<k;
}
