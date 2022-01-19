#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,q;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>q;
    int a[n][m],b[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>b[i][j];
    }
    int x,y,r_x,r_y;
    int a_x,a_y,a_r_x,a_r_y;
    int b_x,b_y,b_r_x,b_r_y;
    int ka,kb,tmp1,tmp2;
    while(q--){
        tmp1=1e9,tmp2=1e9;
        cin>>a_y>>a_x>>a_r_y>>a_r_x;
        if(a_r_x==0&&a_r_y==0)
            ka=-1;
        else{
            if(a_r_x<0)
                tmp1=(a_x-1)/(a_r_x*(-1))+1;
            else if(a_r_x>0)
                tmp1=(m-a_x)/a_r_x+1;
            if(a_r_y<0)
                tmp2=(a_y-1)/(a_r_y*(-1))+1;
            else if(a_r_y>0)
                tmp2=(n-a_y)/a_r_y+1;
            ka=min(tmp1,tmp2);
        }
        cin>>b_y>>b_x>>b_r_y>>b_r_x;
        tmp1=1e9,tmp2=1e9;
        if(b_r_x==0&&b_r_y==0)
            kb=-1;
        else{
            if(b_r_x<0)
                tmp1=(b_x-1)/(b_r_x*(-1))+1;
            else if(b_r_x>0)
                tmp1=(m-b_x)/b_r_x+1;
            if(b_r_y<0)
                tmp2=(b_y-1)/(b_r_y*(-1))+1;
            else if(b_r_y>0)
                tmp2=(n-b_y)/b_r_y+1;
            kb=min(tmp1,tmp2);
        }
        if(ka==kb){
            for(int ax=a_x,ay=a_y,bx=b_x,by=b_y,k=0;k<ka;k++){
                swap(a[ay-1][ax-1],b[by-1][bx-1]);
                ax+=a_r_x,ay+=a_r_y,bx+=b_r_x,by+=b_r_y;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j];
            if(j!=(m-1)) cout<<" ";
        }
        cout<<"\n";
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<b[i][j];
            if(j!=(m-1)) cout<<" ";
        }
        cout<<"\n";
    }
}
