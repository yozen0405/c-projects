#include<bits/stdc++.h>
using namespace std;
int n,k,a=0;
vector<int> pal[1000005];
int main()
{
    int a,b;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        cin>>a>>b;
        pal[a].push_back(b);
        pal[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        sort(pal[i].begin(),pal[i].end());
    }
    for(int i=1;i<=n;i++){
        if(!pal[i].empty()){
                for(int j=0;j<(int)pal[i].size();j++){
                if(j==0||pal[i][j]!=pal[i][j-1]){
                    cout<<pal[i][j];
                    if(j!=(int)pal[i].size()-1) cout<<" "; //不連續的數字才能輸出空格
                }
            }
            cout<<'\n';
        }
        else cout<<"qq\n";
    }
    return 0;
}
 
