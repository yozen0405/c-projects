#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
int n,L,ans;
set <int> st;  //cut point
vector <pair<int,int>> arr;  //x as the index ,y as value
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>L;
    st.insert(0);
    st.insert(L);
    int a,b;
    for(int i=0;i<n;i++){
            cin>>a>>b;
            arr.push_back({b,a});
    }
    sort(arr.begin(),arr.end());
    for(auto [i,x]:arr){
        st.insert(x);
        set<int>::iterator it = st.find(x);
        //cout << *it << "\n";
        ans += (*next(it))-(*prev(it));
    }
    cout << ans << "\n";
}
