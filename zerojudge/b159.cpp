#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,target,k;
signed main(){
    cin>>n>>k;
    vector<int> arr(k);
    for(int i=0;i<k;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int l=0,r=k-1;
    int cnt=0;
    while(r>=l){
        if(l==r){
            l++;
            cnt++;
        }
        else if(arr[l]+arr[r]>n){
            r--;
            cnt++;
        }
        else{
            l++;
            r--;
            cnt++;
        }
        
    }
    cout<<cnt<<"\n";
}
