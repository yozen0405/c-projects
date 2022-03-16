#include <bits/stdc++.h>
#define int long long
#define N 100001
using namespace std;
int n,m,a[N];
typedef pair<int, int> pi;
class cmp
{
public:
    bool operator()(pair<int,int> x,pair<int,int> y) {
        return x.first*y.second>y.first*x.second;
    }
};
signed main(){
    ios::sync_with_stdio(0);
    cin>>n;
    priority_queue<pi, vector<pi>, cmp > pq;
    int b;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b;
        pq.push({a[i],b}); //w,f
    }
    int w=0,total=0;
    for(int i=0;i<n;i++){
        total+=w*pq.top().second;
        w+=pq.top().first;
        //cout<<pq.top().second<<","<<pq.top().first<<"\n";
        pq.pop();
    }
    cout
