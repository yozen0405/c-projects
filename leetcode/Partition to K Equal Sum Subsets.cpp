#define lowbit(x) (x & (-x))
class Solution {
public:
    int dp[1<<16];
    int sum[1<<16];
    int tar=0;
    int dfs(int mask){
        if(~dp[mask]) return dp[mask];
        if(sum[mask]==tar) return dp[mask]=1;
        dp[mask]=0;
        for(int s=mask;s>0;s=(s-1)&mask){
            if(sum[s]==tar){
                dp[mask] |= dfs(mask^s);
            }
        }
        return dp[mask];
    }
    bool canPartitionKSubsets(vector<int>& a, int k) {
        int n = a.size();
        for(auto ele:a) tar+=ele;
        if(tar%k) return 0;
        tar/=k;
        for(int U=1;U<(1<<n);U++){
            int idx = __builtin_ctz(lowbit(U));
            sum[U]=sum[U-lowbit(U)]+a[idx];
        }
        memset(dp, -1, sizeof(dp));
        return dfs((1<<n)-1);

    }
};
