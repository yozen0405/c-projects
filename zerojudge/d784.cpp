#include <bits/stdc++.h>
#define N 101
using namespace std;
int n,num,arr[N],sum[N];
signed main(){
    cin>>num;
    for(int i=0;i<num;i++){
        int maxi=-1e9;
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>arr[j];
            if(sum[j-1]+arr[j]>arr[j])
                sum[j]=sum[j-1]+arr[j];
            else
                sum[j]=arr[j];
            maxi=max(maxi,sum[j]);
        }
         cout<<maxi<<"\n";
    }

}
