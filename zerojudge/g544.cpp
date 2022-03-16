#include <bits/stdc++.h>
#define int long long
using namespace std;
int N,K;
struct node{
    int s,w;
}arr[1000000];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>arr[i].s;
    }
    stack<pair<int,int>> stc;
    cin>>arr[0].w;
    stc.push({arr[0].s,arr[0].w}); //s extent, w attributes
    int ans=arr[0].s; //replace ,revalue
    for(int i=1;i<N;i++){
        cin>>arr[i].w;
        if(stc.top().second!=arr[i].w){
            stc.push({arr[i].s,arr[i].w});
            ans+=arr[i].s;
            //cout<<"i(1)="<<i<<"\n";
        }
        else{
            if(arr[i].s>stc.top().first){ //add in
                ans-=stc.top().first;
                ans+=arr[i].s;
                stc.pop();
                stc.push({arr[i].s,arr[i].w});
                //cout<<"i(2)="<<i<<"\n";
            }
        }
        //cout<<"ans:"<<ans<<"\n";
        //cout<<"stc top:"<<stc.top().first<<","<<stc.top().second<<"\n";
    }
    cout<<ans;
}
