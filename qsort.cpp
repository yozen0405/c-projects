class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dsc={0,6,29};
        vector<vector<int>> dp(366,vector<int>(dsc.size()));
        for(int i=1;i<=days.back();i++){
            for(int j=0;j<dsc.size();j++){
                dp[i][j]=0x3f3f3f3f;
                for(int k=0;k<dsc.size();k++){
                    if(i-dsc[j]<0) continue;
                    dp[i][j]=min(dp[i][j],dp[i-dsc[j]][k]+costs[j]);
                }
            }
        }
        return min({dp[days.back()][0],dp[days.back()][1],dp[days.back()][2]});
    }
};
