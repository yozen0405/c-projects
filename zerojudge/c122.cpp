#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0;
int arr[100000];
signed main(){
    set<int> st;
    st.insert(1);
    int i=0;
    for(auto it=st.begin();it!=st.end()&&i<5842;it++,i++){
        arr[i]= *it;
        st.insert(*it*2);
        st.insert(*it*3);
        st.insert(*it*5);
        st.insert(*it*7);
    }
    while(true){
        cin>>n;
        if(n==0) break;
        if(n%100<=20&&n%100>=11) cout<<"The " <<n<<"th"<< " humble number is "<<arr[n-1]<<".\n";
        else if(n%10==1) cout<<"The " <<n<<"st"<< " humble number is "<<arr[n-1]<<".\n";
        else if(n%10==2) cout<<"The " <<n<<"nd"<< " humble number is "<<arr[n-1]<<".\n";
        else if(n%10==3) cout<<"The " <<n<<"rd"<< " humble number is "<<arr[n-1]<<".\n";
        else cout<<"The " <<n<<"th"<< " humble number is "<<arr[n-1]<<".\n";
    }
}
