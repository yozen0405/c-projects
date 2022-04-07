#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int a,tot=0;
    vector<int> pref(n+1);
    for(int i=1;i<=n;i++){
      cin>>a;
      pref[i]=pref[i-1]+a;
      tot=pref[i];
    }
    int p;
    auto pos=pref.begin()+1;
    auto prev_pos=pref.begin();
    while(m--){
      cin>>p;
      p%=tot;
      prev_pos=pos;
      pos=lower_bound(pref.begin(),pref.end(),*(pos-1)+p);
      if(pos==pref.end()){
        if(pos==pref.end()) pos-=1;
        p-=*(pos-1)-*(prev_pos-1);
        pos=pref.begin()+1;
        if(p>0){
          pos=lower_bound(pref.begin(),pref.end(),p)+1;
        } 
      }
      else{
        pos+=1;
      }
      cout<<pos-pref.begin()-1<<"\n";
    }
    
}
