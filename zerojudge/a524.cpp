#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0;
map<int,int> mp;
int arr[10];
void rec(int ind){
    if(ind==n){
        for(int i=0;i<n;i++){
            cout<<arr[i];
        }
        cout<<"\n";
    }
    for(int i=n;i>=1;i--){
        if(mp[i]==1) continue;
        mp[i]=1;
        arr[ind]=i;
        rec(ind+1);
        mp[i]=0;
    }
}
signed main(){
    while(cin>>n){
        rec(0);
    }
}
