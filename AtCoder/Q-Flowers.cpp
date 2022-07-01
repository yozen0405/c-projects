#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
using namespace std;

const int INF=0x3f3f3f3f;
const int M=1e9+7;
const int maxn=2e5+5;
int n;
int bit[maxn],a[maxn],w[maxn];

int query(int x){
    int ret=0;
    while(x>0){
        ret=max(ret,bit[x]);
        x-=lowbit(x);
    }
    return ret;
}

void modify(int x,int d){
    while(x<=n){
        bit[x]=max(bit[x],d);
        x+=lowbit(x);
    }
}

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int ret=query(a[i])+w[i];
        modify(a[i],ret);
    }
    cout<<query(n);
}
