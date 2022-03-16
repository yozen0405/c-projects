#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0;
int arr[5];
signed main(){
    cin>>n;
    while(n--){
        for(int i=0;i<4;i++){
            cin>>arr[i];
        }
        if(arr[1]-arr[0]==arr[2]-arr[1]){
            arr[4]=arr[3]+arr[1]-arr[0];
        }
        else if(arr[1]/arr[0]==arr[2]/arr[1]){
            arr[4]=arr[3]*(arr[1]/arr[0]);
        }
        for(int i=0;i<5;i++) cout<<arr[i]<<" ";
        cout<<"\n";
    }
}
