#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    vector<int> v{1,3,5,7,9};
    int l=0,r=v.size()-1;
    int target=3;
    int i=0;
    while(l<r){
        int mid=(l+r)/2;
        if(v[mid]<=target){
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout<<l;
}
