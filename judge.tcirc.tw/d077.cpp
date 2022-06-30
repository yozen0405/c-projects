#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;
int seg[maxn*4];
int a[maxn];

// RMQ
void modify(int u,int l,int r,int pos,int val){
    if(l==r){
        seg[u]=val;
        return;
    }
    int mid=(l+r)>>1;
    int lc=2*u,rc=2*u+1;
    if(pos<=mid) modify(lc,l,mid,pos,val);
    else modify(rc,mid+1,r,pos,val);
    seg[u]=min(seg[lc],seg[rc]);
}

int query(int u,int l,int r,int qL,int qR){
    if(r<qL||l>qR) return INF;
    if(qL<=l&&r<=qR){
        return seg[u];
    }
    int mid=(l+r)>>1;
    int lc=2*u,rc=2*u+1;
    return min(query(rc,mid+1,r,qL,qR),query(lc,l,mid,qL,qR));
}

signed main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    //dp[i]在i放基地台的答案
    //轉移: dp[i]=a[i]+min(dp[i-2k-1]...dp[i-1])
    for(int i=1;i<=k+1;i++){
        //前面放了也是多餘的，因為自己的都會把範圍全部涵蓋
        modify(1,1,n,i,a[i]);
    }
    for(int i=k+2;i<=n;i++){
        //[i-2k-1,i-1]
        int l=max(i-2*k-1,1LL);
        int r=i-1;
        int ret=query(1,1,n,l,r)+a[i];
        modify(1,1,n,i,ret);
    }
    cout<<query(1,1,n,n-k,n);
}
