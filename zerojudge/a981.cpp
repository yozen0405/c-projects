#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int arr[30];
int ans[30];
bool is_ans=0;
void rec(int sum,int ind,int len,bool get){ 
    /*
    sum->我目前的加總(還沒加ind這項)，
    ind->我現在想加的項，
    len還沒加ind項的ans長度，
    get要不要加ind這項
    */
    if(get){
        sum+=arr[ind];
        ans[len]=arr[ind];
        len++;
        ind++;
    }
    else ind++;
    if(sum==m){
        is_ans=true;
        for(int i=0;i<len;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    if(ind==n||sum>m){ 
        //如果我現在要預處理的那一項已經超出範圍了或sum根本已經過大(TLE的關鍵)，就return
        return;
    }
    rec(sum, ind, len, 1);
    rec(sum, ind, len, 0);
}
signed main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n);
    rec(0,0,0,1);
    rec(0,0,0,0);
    if(!is_ans) cout<<"-1";
}
