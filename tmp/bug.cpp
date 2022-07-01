#define lowbit(x) x & (-x)
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& a, int k) {
        int n = a.size();
        int tar=0;
        for(auto ele:a) tar+=ele;
        if(tar%k) return 0;
        tar/=k;
        vector<int> sum(1<<n);
        for(int U=1;U<(1<<n);U++){
            sum[U]=sum[U-lowbit(U)]+a[log2(lowbit(U))];
        }
        vector<int> dp(1<<n);
        dp[0]=true;
        for(int U=1;U<(1<<n);U++){
            for(int S=U;S>=0;S=(S-1)&U){
                if(S==tar&&dp[U^S]){
                    dp[U]=true;
                    break;
                }
            }
        }
        return dp[(1<<n)-1];
    }
};
