#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m;

signed main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin>>n;
    vector<int> v(n);
    set<int> st;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(!v[i]) st.insert(i);
    }
    cin>>m; 
    int t,val;
    while(m--){
        cin>>t;
        if(t==1){
            cin>>val;
            if(st.size()){
                v[*st.begin()]=val;
                st.erase(*st.begin()); 
            }
        }
        else if(t==2){
            cin>>val;
            if(v.size()-1>=val){
                v[val]=0;
                st.insert(val);
            }
        }
        else{
            if(st.size()){
                cout<<*st.begin()<<"\n";
            }
            else{
                cout<<"-1\n";
            }
        }
    }
}
// 2 3
// 3 1 2
// 8 5 4
