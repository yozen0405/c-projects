#include <bits/stdc++.h>
#define N 1000000
#define int long long
using namespace std;
int n,c,arr[N],num[11],ans=0; //num[i] 紀錄arr[l]~arr[r] i=1~10 出現的次數
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>c;
	int k=0,r; 
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
        if(num[arr[i]]==0){
            k++;
            num[arr[i]]++;
            if(k==c){ //找到1~c最後出現至少一次的數字的index
              r=i;
              break;
	    }
        }
	else num[arr[i]]++;
    }
    if(k!=c){
        cout<<0<<"\n";
        return 0;
    }
    for(int l=0;l<n;l++){
        if(l>0){
            num[arr[l-1]]-=1; //扣掉之前左界包含數字的數量
            if(num[arr[l-1]]==0) k--;
            while(r<n-1&&k<c){ //增加右界找目前長度最小的範圍
                r++;
                if(num[arr[r]]==0) k++;
                num[arr[r]]++; 
            }
            if(num[arr[l-1]]==0) //如果都找不到代表不用繼續了
                break;
        }
        ans+=n-r; //(n-1)-r+1
    }
    cout<<ans<<"\n";
}
