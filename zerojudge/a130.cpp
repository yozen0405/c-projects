#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0;
vector<pair<string,int>> vec;
int cmp(pair<string,int> a,pair<string,int> b){
    return a.second>b.second;
}
signed main(){
    cin>>n;
    for(int j=1;j<=n;j++){
        string s;int num;
        int mx=-1e9;
        for(int i=0;i<10;i++){
            cin>>s>>num;
            vec.push_back({s,num});
            mx=max(mx,num);
        }
        sort(vec.begin(),vec.end(),cmp);
        cout<<"Case #"<<j<<":"<<"\n";
        for(int i=0;i<10;i++){
            if(vec[i].second==mx){
                cout<<vec[i].first<<"\n";
            }
            else{
                break;
            }
        }
        vec.clear();
    }
}
