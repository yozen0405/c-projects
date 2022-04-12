#include <bits/stdc++.h>

#define int long long
using namespace std;
int arr[100000];
int n,k;
void cal(int l,int r){
    if(l==r){
        cout<<arr[l];return;
    } 
    swap(arr[l],arr[r]);
    int i=l-1;
    for(int j=l;i<=r;j++){
        if(j==r){
            i++;
            swap(arr[i],arr[r]);
            break;
        }
        if(arr[j]<arr[r]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    if(i==k-1){
        cout<<arr[i];return;
    }
    if(i>k-1){
        cal(l,i-1);
    }
    else cal(i+1,r);
}
signed main(){
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    cal(0,n-1);
}
    
