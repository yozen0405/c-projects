#include <bits/stdc++.h>
#define int long long
#define N 10000
using namespace std;
int n;
signed main()
{
    int val[5]={1,5,10,25,50},w[N];
    memset(w,0,N);
    w[0]=1;
    for(int i=0;i<5;i++){
        for(int j=val[i];j<=N;j++){
            w[j]+=w[j-val[i]];
        }
    }
    while(cin>>n){
        cout<<w[n]<<"\n";
    }
}
