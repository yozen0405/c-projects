#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int h[200001],w[5001];
signed main(){
    cin>>n>>k;
    int r;
    for(int i=0;i<n;i++){
        cin>>h[i];
        r=max(h[i],r); //取最大的height+1作為右界
    }
    r++;
    for(int i=0;i<k;i++) cin>>w[i];
    int l=1;
    while(r-l>1){
        int mid=(r+l)/2; //高度
        int cnt=0,now=0;//cnt:目前能貼的高度,now:貼到的海報index
        bool ok=false;//在mid這高度可不可貼
        for(int i=0;i<n;i++){ //掃過所有的木板
            if(h[i]>=mid){ //在mid這高度可以貼
                cnt++;
                if(w[now]<=cnt){ //可以貼了
                    cnt-=w[now]; 
                    if(now==k-1){ //連最後一個海報都貼玩了
                        ok=true;
                        break;
                    }
                    now++;
                }
            }
            else cnt=0; //木板要可以連續貼，否則直接歸0
        }
        if(ok) l=mid;
        else r=mid;
    }
    cout<<l<<"\n";
}
