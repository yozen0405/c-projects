class Solution {
public:
    int shortestPathLength(vector<vector<int>>& G) {
        int n=G.size();
        if(n==0) return 0;
        const int INF=0x3f3f3f3f;
        const int maxn=21;
        vector<vector<int>> d(n,vector<int>(n,INF));
        vector<int> m;
        for(int i=0;i<n;i++){
            for(auto u:G[i]){
                d[u][i]=1;
                d[i][u]=1;
            }
        }
        //floyd-warshall
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
        for(int i=0;i<maxn;i++){
            m.push_back(1<<i);
        }
        vector<vector<int>> dp(n,vector<int>(1<<n));
        int ans=INF;
        //TSP
        //dp[u][S] 最後一個停在u,走過了集合S這些點
        for(int mask=0;mask<(1<<n);mask++){
            vector<int> b;
            for(int i=0;i<maxn;i++){
                if(m[i]&mask) b.push_back(i);
            }
            for(int i=0;i<b.size();i++){
                dp[b[i]][mask]=INF;
                if(b.size()==1) dp[b[i]][mask]=0;
                for(int j=0;j<b.size();j++){
                    if(i==j) continue;
                    int v=b[i],u=b[j];
                    dp[v][mask]=min(dp[v][mask],dp[u][mask^(1<<v)]+d[v][u]);
                    if(mask==(1<<n)-1) ans=min(ans,dp[v][mask]);
                }
            }
        }
        if(ans==INF) return 0;
        return ans;
        

    }
};
