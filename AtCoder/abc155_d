//https://atcoder.jp/contests/abc155/tasks/abc155_d
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,target,k;
int arr[1000000];
map<int,int> mp;
signed main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int L=-1e18,R=1e18;
    while(R-L>1){
        int MID=(L+R)/2;
        int count=0;
        for(int i=0;i<n;i++){ // search how many pairs lower than mid
            if(arr[i]<0){//對於arr[i]有幾個跟他乘會比MID小
                int l=i, r=n;
                while(r-l>1){
                    int mid=(l+r)/2;
                    if(arr[i]*arr[mid]<=MID) r=mid; //arr[mid]是正
                    else l=mid;//arr[mid]是負
                }
                count+=n-r; //l:跟他乘恰大於MID ，又r=l+1，n-r相當於((n-1)-(l+1))+1，是r~n-1小於MID的區間
            }
            else{//因為arr[i]乘的一定是正數或0，所以需要看有幾個正數比MID小
                int l=i, r=n; 
                while(r-l>1){
                    int mid=(l+r)/2;
                    if(arr[i]*arr[mid]<=MID) l=mid;
                    else r=mid;
                }
                count+=l-i;//l:跟他乘恰大於MID，l-i相當於((l-1)-i)+1
            }
        }
        if(count<k) L=MID;//mid<target
        else R=MID;
    }
    cout<<R;
}
