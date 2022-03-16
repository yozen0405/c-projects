#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=0;
int dp[20][12],arr[20],sum[20];//dp[長度][數字]
signed main(){
    //建表
    dp[1][10]=1;
    /*
        ex:dp(3, 7)=?
        888,889,899的情況(把開頭的8調換成7)
        再加上
        77,78,79(將開頭加上7(代表第二位從7開始的情況因為階梯數字可以等於
        上面的只涵蓋到了第二位>=8的情況))
        dp(3, 7)=dp(2, 7)+dp(3, 8)

    */
    for(int len=1;len<=19;len++){
        for(int num=9;num>=1;num--){
            dp[len][num]=dp[len-1][num]+dp[len][num+1];
            sum[len]+=dp[len][num];
        }
        
    }
    while(cin>>n){
        ans=0;
        int ind;
        for(int i=1;i<20;i++){
            arr[i]=n%10;
            n/=10;
            if(n==0){
                ind=i;
                break;
            }
        }
        for(int len=1;len<ind;len++){
            ans+=sum[len]; //先加上總位數之下的情況
        }
        for(int i=ind;i>0;i--){ //從高位數讀到低位數
            int first,previous_num;
            if(i==ind) previous_num=1; //最高項沒有前一項
            else{
                previous_num=arr[i+1];
                if(arr[i]<arr[i+1]) break; //現在這一項比之前那一項小(全部不適階梯數字，不用玩了)

            }
            if(i==1) first=arr[i]; //跑到最後一項了，全部的情形都應該要跑進去
            else first=arr[i]-1;//-1因為要留給下一項處理
            for(int j=first;j>=previous_num;j--){
                ans+=dp[i][j];
            }
        }
        cout<<ans<<"\n";
    }
}
