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
			mp[v[i]]++;
			if(mp[v[i]]>n/2){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"-1\n";
			continue;
		}
		mp.clear();
		for(int k=1;k<=2e6;k++){
			for(int i=0;i<n;i++){
				int mod=
			}
			
		}
	}
}
