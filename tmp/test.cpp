#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct node{
    string s=""; 
    node *next=nullptr;
}arr[1000001];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].s;
    }
    int u,v;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        arr[u].s+=arr[v].s;
        arr[v].s.clear();
        if(i==n-1) cout<<arr[u].s;
    }
    
