#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,pref[1000000],cur=1;
int cmp(pair<int,int> a,pair<int,int> b){
  if(a.first==b.first) return a.second<b.second;
  return a.first<b.first;
}
int rec(vector<pair<int,int>>& vec,int l,int r){
  if(l==r) return pref[r]-pref[l-1];
  while(l>vec[cur].second||r<vec[cur].second) cur++;
  int m=vec[cur].second;
  if(pref[m-1]-pref[l-1]<=pref[r]-pref[m]) l=m+1;
  else r=m-1;
  return rec(vec,l,r);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    vector<pair<int,int>> srt(n+1); //value,index
    for(int i=1;i<=n;i++){
      cin>>srt[i].first;
      srt[i].second=i;
      pref[i]=pref[i-1]+srt[i].first;
    }
    sort(srt.begin()+1,srt.end(),cmp);
    cout<<rec(srt,1,n);
}
