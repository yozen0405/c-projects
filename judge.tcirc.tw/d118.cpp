#include<bits/stdc++.h>
#define int long long
using namespace std;
 
struct Job {
    int start, finish, profit;
};
 
int bin_search(vector<Job> const &jobs, int n)
{
    int l=0,r=n;
    while(r-l>1){
        int mid=(l+r)>>1;
        if(jobs[mid].finish<jobs[n].start){
            l=mid;
        }
        else r=mid;
    }
    if(jobs[l].finish>=jobs[n].start) return -1;
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
        int index = bin_search(jobs, i);
        int sum = jobs[i].profit;
        if (index != -1) {
            sum += dp[index];
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
