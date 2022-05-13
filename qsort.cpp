#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=2e5+5;
const int INF=0x3f3f3f3f;
int n,q;
int a[maxn];
int seg[4*maxn];

void build(int u,int l,int r){
    //cout<<"ho\n";   
    if(l==r){
        seg[u]=a[l];
        return;
    }
    int mid=(l+r)/2;
    int lc=2*u,rc=2*u+1;
    
    build(lc,l,mid);
    build(rc,mid+1,r);
    seg[u]=max(seg[lc],seg[rc]);
}
int query(int u,int l,int r,int qL,int qR){
    if(r < qL || qR < l) return INF;  
    if(qL<=l && r<=qR){
        return seg[u];
    }
    int mid=(l+r)/2;
    int lc=2*u,rc=2*u+1;
    return max(query(lc,l,mid,qL,qR),query(rc,mid+1,r,qL,qR));
}                                                               
pair<int,int> find(int u,int l,int r,int x){
    if(l==r){
        return {r,seg[u]};
    }
    int mid=(l+r)/2;
    int lc=2*u,rc=2*u+1;
    if(seg[lc]>=x){
        return find(lc,l,mid,x);
    }
    else{
        return find(rc,mid+1,r,x);
    }   
}
void modify(int u,int l,int r,int pos,int val){
    if(l==r){
        seg[u]=val;
        return;
    }
    int mid=(l+r)/2;
    int lc=2*u,rc=r*u+1;
    if(pos<=mid){
        modify(lc,l,mid,pos,val);
    }
    else{
        modify(rc,mid+1,r,pos,val);
    }
    seg[u]=max(seg[lc],seg[rc]);
}

signed main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    } 
    int k;
    build(1,1,n);
    while(q--){
        cin>>k;
        auto ret=find(1,1,n,k);
        if(ret.second>=k){
            cout<<ret.first<<" ";
            modify(1,1,n,ret.first,ret.second-k);
        }
        else{
            cout<<"0 ";
        }
    }
}
/*
8 1
3 2 4 1 5 5 2 6
9


*/
