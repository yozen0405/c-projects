#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int cmp(pair<int,int> a, pair<int,int> b){
    return a.second+a.first-b.second>b.first+b.second-a.second;
    //票數誰拉的大
}
signed main(){
    cin>>n;
    vector<pair<int,int>> vec(n);
    int enemy=0,mine=0;
    for(int i=0;i<n;i++){ //second enemy, first mine
        cin>>vec[i].second>>vec[i].first;
        enemy+=vec[i].second;
    }
    sort(vec.begin(),vec.end(),cmp);
    for(int i=0;i<n;i++){
        mine+=vec[i].second+vec[i].first;
        enemy-=vec[i].second;
        if(mine>enemy){
            cout<<i+1;
            break;
        }
    }
}
