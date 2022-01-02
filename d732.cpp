#include <bits/stdc++.h>
#define N 110
using namespace std;
vector<int> a;
int n,k;
int bin(int val){
    if(a[n-1]<val || a[0]>val) return 0;
    int l=0,r=a.size()-1;
    while(l!=r){
        int mid=(l+r)/2;
        if(a[mid]>=val)
            r=mid;
        else
            l=mid+1;
    }
    if(a[l]!=val) return 0;
    return l+1;
}
signed main(){
    int d;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>d;
        a.push_back(d);
    }
    for(int i=0;i<k;i++){
        cin>>d;
        cout<<bin(d)<<'\n';
    }
}
