#include <bits/stdc++.h>
#define int long long
using namespace std; //val(val-1)/2*m val=有幾項
int n,m;
int bin(){
    int l=0,r=2147483647,mid,sum;
    while(l!=r){
        mid=l+(r-l)/2;
        sum=mid+(mid*(mid-1)/2)*m;
        //cout<<sum<<'\n';
        if(sum>=n)
            r=mid;
        else
            l=mid+1;
    }
    return l+(l*(l-1)/2)*m==n;
}
signed main(){
        while(cin>>n>>m){
        if(bin()) cout<<"Go Kevin!!\n";
        else cout<<"No Stop!!\n";
        }
}
