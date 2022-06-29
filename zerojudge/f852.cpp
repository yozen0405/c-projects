#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 5e4+5;
vector<int> G[maxn];
int n,k;
int dp[1001][81][5];
vector<string> s;
map<char,int> mp={{'@',0},{'A',1},{'U',2},{'C',3},{'G',4}};
//dp[u][pos][state]最少的距離

void dfs(int u,int pos){
    if(G[u].size()==0){
        if(mp[s[u][pos]]==0){
            dp[u][pos][0]=0;
        }
        else{
            int st=mp[s[u][pos]];
            for(int i=1;i<mp.size();i++){
                dp[u][pos][i]=INF;
            }
            dp[u][pos][st]=0;
            dp[u][pos][0]=0;
        }
    }
    else{
        for(auto v:G[u]){
            dfs(v,pos);
        }
        int st=mp[s[u][pos]];
        if(st==0){
            for(auto v:G[u]){
                for(int i=1;i<mp.size();i++){
                    dp[u][pos][i]+=min(dp[v][pos][i],dp[v][pos][0]+1);
                }
            }
            dp[u][pos][0]=min({dp[u][pos][1],dp[u][pos][2],dp[u][pos][3],dp[u][pos][4]});
        }
        else{
            for(int i=1;i<mp.size();i++){
                dp[u][pos][i]=INF;
            }
            dp[u][pos][st]=0;
            for(auto v:G[u]){
                dp[u][pos][st]+=min(dp[v][pos][st],dp[v][pos][0]+1);
            }
            dp[u][pos][0]=dp[u][pos][st];
        }
    }

}

signed main(){
    cin>>n>>k;
    int rt=0;
    s.resize(n+1);
    string str;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v>>str;
        s[u]=str;
        if(u==v){
            rt=u;
            continue;
        }
        G[v].push_back(u);
    }
    int ans=0;
    for(int i=0;i<k;i++){
        dfs(rt,i);
        ans+=dp[rt][i][0];
        //cout<<dp[rt][i][0]<<"\n";
    }
    cout<<ans;
}
