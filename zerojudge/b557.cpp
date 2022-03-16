#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0;
map<int,int> mp;
int arr[101];
signed main(){
    cin>>n;
    while(n--){
        int t;
        ans=0;
        cin>>t;
        for(int i=0;i<t;i++){
            cin>>arr[i];
        }
        sort(arr,arr+t);
        for(int i=0;i<t-2;i++){
            if(i==t-2) break;
            for(int j=i+1;j<t-1;j++){
                for(int k=j+1;k<t;k++){
                    if(arr[k]*arr[k]==(arr[j]*arr[j]+arr[i]*arr[i])){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
}
