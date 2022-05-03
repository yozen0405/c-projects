https://codeforces.com/problemset/problem/1593/D2
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans,t;
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> v(n);
		map<int,int> mp;
		bool flag=0;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		int k=2000006,mx=0;
		flag=0;
		for(int i=0;i<n;i++){
			int mod=v[i]%k;
			if(mod<0) mod+=k;
			mp[mod]++;
			if(mp[mod]>=n/2){
				mx=max(mx,k);
				flag=1;
				break;
			}
		}
		mp.clear();
		if(flag==1){
			cout<<"-1\n";
			continue;
		} 
		set<int> prime;
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
			int d=abs(v[i]-v[j]);
			for(int p=1;p*p<=d;p++){
				if(d%p==0){
					prime.insert(p);
					prime.insert(d/p);
				}
			}
		}
		}
		vector<int> rv;
		for(auto k:prime) rv.push_back(k);
		reverse(rv.begin(),rv.end());
		mp.clear();
		mx=0;
		for(auto k:rv){
			for(int i=0;i<n;i++){
				int mod=v[i]%k;
				if(mod<0) mod+=k;
				mp[mod]++;
				if(mp[mod]>=n/2){
					mx=max(mx,k);
					break;
				}
			}
			mp.clear();
		}
		cout<<mx<<"\n";
	}
}
