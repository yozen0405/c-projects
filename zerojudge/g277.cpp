#include <bits/stdc++.h>
#define int long long
#define N 300005
#define x first
#define y second
using namespace std;
int n,arr[N],pref[N]; //arr unsort, pref sum
pair<int,int> sorted[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>sorted[i-1].x;
        arr[i]=sorted[i-1].x;
        sorted[i-1].y=i;
        pref[i]=pref[i-1]+arr[i];
    }
    sort(sorted,sorted+n);
    int r=n,l=1,ind=0;
    while(r>l){
        while(sorted[ind].y>r || sorted[ind].y<l) ind++;
        int left=pref[sorted[ind].y-1] - pref[l-1];
        int right=pref[r]-pref[sorted[ind].y];
        if(left>right) r=sorted[ind].y-1;
        else l=sorted[ind].y+1;
    }
    cout<<arr[l];
}
