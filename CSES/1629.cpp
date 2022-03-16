//https://cses.fi/problemset/task/1629
#include <bits/stdc++.h>
#define N 1000000
using namespace std;
int n=0,num,arr[N],sum[N];
signed main(){
    cin>>num;
    vector<pair<int,int>> vec(num);
    for(int i=0;i<num;i++){
        cin>>vec[i].second>>vec[i].first;
    }
    sort(vec.begin(),vec.end());
    int pref_r=0;
    for(auto [r,l]:vec){
        if(l>=pref_r){
            n++;
            pref_r=r;
        }
    }
    cout<<n;

}
