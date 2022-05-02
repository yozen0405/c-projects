//https://codeforces.com/contest/1175/problem/C
#include <bits/stdc++.h>
#define int long long
int t,n,k;
int arr[1000000];
using namespace std;
bool check(int m){
    for(int i=0;i<=n-k;i++){
        //m是目前的距離，使對於每一個k段，只有一個最小的k段的距離是m
        if(arr[i+k-1]-arr[i]<=2*m){ //2*m就是arr[i+k-1]~arr[i]最長的距離，也就是第K大的距離，return true代表可以更小(因為有一段區間符合)
            return true;
        }
    }
    return 0;
}
signed main(){
    cin>>t;
    while(t--){
        cin>>n>>k;
        k++;
        for(int i=0;i<n;i++) cin>>arr[i];
        int l=-1,r=2e9+3;
        while(l<r-1){
            int mid=(l+r)>>1;
            if(check(mid)){
                r=mid;
            }
            else{
                l=mid;
            }
        }
        int ans=0;
        for(int i=0;i<=n-k;i++){
            if(arr[i]+r>=arr[i+k-1]-r){
                ans=arr[i]+r;
            }
        }
        cout<<ans<<"\n";
    }
    
}   
