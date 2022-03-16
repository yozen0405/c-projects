#include <bits/stdc++.h>
#include <vector>
#define int long long
using namespace std;
int n,m;
int q;
int arr[501][501];
bool is_placed[501][501];
signed main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    int q;
    cin>>q;
    int x,y;
    for(int k=0;k<q;k++){
        int total=0;
        cin>>y>>x;
        y--;
        x--;
        for(int i=y;i<n;i++){
            if(is_placed[i][x]) break;
            total+=arr[i][x];
            is_placed[i][x]=true;
        }
        if(y!=0)
            for(int i=y-1;i>=0;i--){
                if(is_placed[i][x]) break;
                total+=arr[i][x];
                is_placed[i][x]=true;
            }
        if(x!=m-1)
            for(int i=x+1;i<m;i++){
                if(is_placed[y][i]) break;
                total+=arr[y][i];
                is_placed[y][i]=true;
            }
        if(x!=0)
            for(int i=x-1;i>=0;i--){
                if(is_placed[y][i]) break;
                total+=arr[y][i];
                is_placed[y][i]=true;
            }
        cout<<total<<"\n";
    }
}

    
