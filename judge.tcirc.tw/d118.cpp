#include<bits/stdc++.h>
#define int long long
using namespace std;
 
struct Job {
    int start, finish, profit;
};

//二分搜最靠近i且沒有重疊的那項
int bin_search(vector<Job> const &jobs, int i)
{
    int l=0,r=i;
    while(r-l>1){
        int mid=(l+r)>>1;
        if(jobs[mid].finish<jobs[i].start){
            l=mid;
        }
        else r=mid;
    }
    if(jobs[l].finish>=jobs[i].start) return -1;
    return l;
}
 
int findMaxProfit(vector<Job> jobs)       
{
    sort(jobs.begin(),
        jobs.end(),
        [](Job &x, Job &y) {
            return x.finish < y.finish;
        });
    int n = jobs.size();
    if (n == 0) {
        return 0;
    }
    vector<int> dp(n);
    dp[0] = jobs[0].profit;
    for (int i = 1; i < n; i++)
    {
        int idx = bin_search(jobs, i);
        //因為dp的序列一定是一個非遞減子序列
        //dp[i]=max(dp[i-1],dp[j]+w[i]) 會繼承dp[i-1]
        //所以greedy想法知道最靠近i且沒有重疊的idx一定是dp值最大的
        int sum = jobs[i].profit;
        if (idx != -1) {
            sum += dp[idx];
        }
        dp[i] = max(sum, dp[i-1]);
    }
    return dp[n-1];
}
 
signed main()
{
    int n;
    cin>>n;
    vector<Job> jobs(n);
    for(int i=0;i<n;i++) cin>>jobs[i].start>>jobs[i].finish>>jobs[i].profit;
    cout <<findMaxProfit(jobs);
 
}
