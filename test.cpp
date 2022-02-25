#include <bits/stdc++.h>
#define int long long
using namespace std;
string n;
int ans=0;
int dp[20][12],arr[20],sum[20];//dp[長度][數字]
const int mod = 1e9 + 7;
signed main(){
    //建表
    dp[1][10]=1;
    for(int len=1;len<=19;len++){
        for(int num=9;num>=1;num--){
            dp[len][num]=dp[len-1][num]+dp[len][num+1];
            sum[len]+=dp[len][num];
            //cout<<"dp"<<"("<<len<<","<<num<<"): "<<dp[len][num]<<"\n";
        }
        
    }
    while(cin>>n){
        ans=0;
        int ind;
        for(int i=1;i<=n.size();i++){
            string s=n.substr(i-1,i);
            arr[n.size()-i+1]=stoll(s);
            cout<<n.size()-i+1<<","<<arr[n.size()-i+1]<<"\n";
        }
        ind=n.size();
        //cout<<"ind:"<<ind<<"\n";
        for(int len=1;len<ind;len++){
            ans+=sum[len];
            ans%=mod;
        }
        for(int i=ind;i>0;i--){ //從高位數讀到低位數
            int first,previous_num;
            if(i==ind) previous_num=1;
            else{
                previous_num=arr[i+1];
                if(arr[i]<arr[i+1]) break;

            }
            if(i==1) first=arr[i];
            else first=arr[i]-1;
            for(int j=first;j>=previous_num;j--){
                ans+=dp[i][j];
                ans%=mod;
            }
        }
        cout<<ans%mod<<"\n";
    }
}
