#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct node{
    int val;
    bool die=false;
    node *next=nullptr;
}arr[1000001];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        arr[i].val=i;
        if(i!=n) arr[i].next=&arr[i+1];
    }
    int u;
    for(int i=1;i<=m;i++){
        cin>>u;
        if(arr[u].next==nullptr||arr[u].die||arr[u].next->die) cout<<"0u0 ...... ?"<<"\n";
        else{
            cout<<arr[u].next->val<<"\n";
            arr[u].next->die=1;
            arr[u].next=arr[u].next->next;
            
        } 
        
    }
}
