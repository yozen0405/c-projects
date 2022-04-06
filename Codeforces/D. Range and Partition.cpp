//https://codeforces.com/contest/1631/problem/D
#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n,k,arr[1000000],pref[1000000],x,y;
bool check(int mid){ //判斷有沒有可以以mid為長度的合法[x,y]區間
    //"總"區間
    for(int i=1;i+mid-1<=n;i++){ //i~i+mid-1 ，x,y只可能在1~n
        if(2*(pref[i+mid-1]-pref[i-1])-n>=k){ 
            x=i;
            y=i+mid-1;
            return true;
        }
    }
    return false;
}
void cal(){
    int out=0,in=0,left=1,cnt=0;
        for(int i=1;i<=n;i++){
            if(cnt==k-1){
                cout<<left<<" "<<n<<"\n";
                return;
            }
            if(x<=arr[i]&&arr[i]<=y){
                in++;
            }
            else{
                out++;
            }
            if(in>out){
                in=0;
                out=0;
                cnt++;
                cout<<left<<" "<<i<<"\n";
                left=i+1;
            }
        }
}
signed main(){
    //https://hackmd.io/@aaKAz8JjSSmDXpSy2N_PFA/SJkfOttX5
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> mp(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        for(int i=1;i<=n;i++) pref[i]=pref[i-1]+mp[i]; 
        //因為a_i<=n，前綴減去複雜度
        int l=1,r=n+1,ansx=0,ansy=0,mid;
        while(l<=r-1){ //二分搜[x,y]長度
            mid=(l+r)/2;
            if(check(mid)){
                ansx=x;
                ansy=y;
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        cout<<ansx<<" "<<ansy<<"\n";
        x=ansx;y=ansy;
        cal();
    }
}
