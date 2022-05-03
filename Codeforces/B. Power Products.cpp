//https://codeforces.com/contest/1246/problem/B
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
map<vector<pair<int,int>>,int> mp;
int prime[1000000],c[1000000];
signed main(){
	cin>>n>>k;
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		int now=0;
		for(int j=2;j*j<=x;j++){
			if(x%j==0){
				prime[now]=j;
				c[now]=0;
				do{
					x/=j;
					c[now]++;
				}while(x%j==0);
				c[now]%=k;
				if(c[now]==0) now--;
				now++;
			}
		}
		if(x>1){
			prime[now]=x;
			c[now]=1;
			now++;
		}
		vector<pair<int,int>> v1;
		vector<pair<int,int>> v2;
		for(int j=0;j<now;j++){
			v1.push_back({prime[j],c[j]});
			v2.push_back({prime[j],k-c[j]});
		}
		ans+=mp[v2];
		//cout<<v1.size()<<"\n";
		mp[v1]++;
	}
	cout<<ans<<"\n";
}
