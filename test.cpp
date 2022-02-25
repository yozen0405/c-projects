#include <bits/stdc++.h>
#define int long long
using namespace std;
string n;
int ans=0;
int dp[20][12],arr[1000001],sum[20];//dp[長度][數字]
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
        ind=n.size();
        //cout<<"ind:"<<ind<<"\n";
        for(int len=1;len<ind;len++){
            ans+=sum[len];
            ans%=mod;
        }
        for(int i=1;i<=ind;i++){ //從高位數讀到低位數
            int first,previous_num;
            string s1=n.substr(i-1,i),s2=n.substr(i-2,i-1);
            int n1=stoll(s1),n2=stoll(s2);
            if(i==1) previous_num=1;
            else{
                previous_num=n2;
                if(s1<s2) break; //現在這項比前一項還小

            }
            if(i==ind) first=n1;
            else first=n1-1;
            for(int j=first;j>=previous_num;j--){
                ans+=dp[i][j];
                ans%=mod;
            }
        }
        cout<<ans%mod<<"\n";
    }
}
