#include <bits/stdc++.h>
using namespace std;
int r,c,k,m,city[50][50],tmp[50][50]={0},dx[3]={-1,0,1},dy[3]={-1,0,1};
signed main(){
    cin>>r>>c>>k>>m;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>city[i][j];
            tmp[i][j]=city[i][j];
        }
    }
    while(m--){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(city[i][j]!=-1){
                    for(auto u:dx){
                        for(auto v:dy){
                            if((u!=0) and (v!=0)) continue;
                            if(u==0 and v==0) continue;
                            int tmp_i=i+v,tmp_j=j+u;
                            if((tmp_i>=r) || (tmp_i<0) || (tmp_j>=c)||(tmp_j<0)) continue;
                            if(city[tmp_i][tmp_j]==-1) continue;
                            tmp[tmp_i][tmp_j]+=city[i][j]/k;
                            tmp[i][j]-=city[i][j]/k;
                            //cout<<"tmp-i:"<<tmp_i<<",tmp-j:"<<tmp_j<<",tmp[tmp_i][tmp_j]:"<<tmp[tmp_i][tmp_j]<<"\n";
                    }
                    }
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                //cout<<tmp[i][j]<<" ";
                if(city[i][j]!=-1)
                    city[i][j]=tmp[i][j];
            }
            //cout<<"\n";
        }
            //cout<<"====\n";
    }
    int maxi=-1e9,mini=1e9;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(city[i][j]==-1) continue;
                    maxi=max(maxi,city[i][j]);
                    mini=min(mini,city[i][j]);
        }
    }
    cout<<mini<<"\n"<<maxi;
}
