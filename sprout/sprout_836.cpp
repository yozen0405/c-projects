#include <bits/stdc++.h>
#define int long long
#define N 1010
using namespace std;
int arr[N][N], maxi=0,adjust=0;
int n, m,t, ans=0,d[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    cin>>n>>m;
    int t2=t;
    int x,y,c;
    while(t--){
        cin>>x>>y>>c;
        if(c==1){
            for(auto [u,v]:d){
                if(x+u>=n||x+u<0||y+v>=m||y+v<0) continue;
                arr[x+u][y+v]+=1;
            }
            arr[x][y]+=1;
        }
        else{
            for(auto [u,v]:d){
                if(x+u>=n||x+u<0||y+v>=m||y+v<0) continue;
                arr[x+u][y+v]-=1;
            }
            adjust+=1;
            arr[x][y]-=1;
        }
    }
    maxi=arr[0][0];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            maxi=max(maxi,arr[j][i]);
    }
    for(int i=0;maxi+adjust>400&&i<t2;i++){
        adjust--;
    }
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            if(arr[j][i]+adjust<0) ans++;
    }
    cout<<ans<<" "<<(maxi+adjust+600)/10<<"."<<(maxi+adjust)%10<<"\n";
    for(int j=0;j<n;j++)
        for(int i=0;i<m;i++){
            if(arr[j][i]==maxi) cout<<j<<" "<<i<<"\n";
    }
}
