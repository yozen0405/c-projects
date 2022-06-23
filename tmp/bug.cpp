#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=20;

struct TwoSAT{
    static const int MAXv = 2*MAXN;
    vector<int> GO[MAXv],BK[MAXv],stk;
    int vis[MAXv];
    int SC[MAXv];
    void imply(int u,int v){ // u imply v
        GO[u].push_back(v);
        BK[v].push_back(u);
    }
    void dfs(int u,vector<int>*G,int sc){
        vis[u]=1, SC[u]=sc;
        for (int v:G[u])
            if (!vis[v])
                dfs(v,G,sc);
        if (G==GO)stk.push_back(u);
    }
    void scc(int n){
        memset(vis,0,sizeof(vis));
        for (int i=0; i<n; i++)if (!vis[i])
            dfs(i,GO,-1);
        memset(vis,0,sizeof(vis));
        int sc=0;
        while (!stk.empty()){
            if (!vis[stk.back()])
                dfs(stk.back(),BK,sc++);
            stk.pop_back();
        }
    }
};


signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s1="",s2="";
        TwoSAT SAT;
        for(int i=0;i<m;i++){
            cin>>s1;
            cin>>s2;
            //+ 2*i m 0
            //- 2*i+1 h 1
            int p1=((s1[0]=='m') ? 1:0),p2=((s2[0]=='m') ? 1:0);
            int num1=s1[1]-'1',num2=s2[1]-'1';
            //cout<<s1<<","<<s2<<","<<num1<<","<<num2<<"\n";
            SAT.imply(num1*2+p1,num2*2+!p2);
            SAT.imply(num2*2+p2,num1*2+!p1);
        }
        SAT.scc(2*n);
        bool flg=0;
        for(int i=0;i<n;i++){
            if(SAT.SC[2*i]==SAT.SC[2*i+1]) flg=1;
            //cout<<SAT.SC[2*i]<<","<<SAT.SC[2*i+1]<<"\n";
        }
        if(flg) cout<<"BAD\n";
        else cout<<"GOOD\n";
    }
}

/*
2 4
h1 m2
m2 m1
h1 h2
m1 h2
*/
