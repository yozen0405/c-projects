#include<bits/stdc++.h>
#define int long long
using namespace std;
int visited[90]={0,1,1};
int f(int m){
    if(visited[m]) return visited[m];
    if(m<=2) return 1;
    visited[m]=f(m-1)+f(m-2);
    return visited[m];
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,m,n,sum,sun;
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>m>>n;
        sum=f(m);
        sun=f(n);
        cout<<__gcd(sum,sun)<<'\n';
    }
    return 0;
}
