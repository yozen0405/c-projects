// Solver: Min-Zheng Shieh
// Expected running time: <1 second

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

void solve()
{
	int N, B, R, ans=0;
	scanf("%d",&N);
	vector<int> p(N+1),d(N+1),c(N+1);
	for(int i=1; i<=N; i++)
		scanf("%d%d%d",&p[i],&d[i],&c[i]);
	scanf("%d%d",&B,&R);
	vector<vector<int>> dp(N+2,vector<int>(R+1));

	// build prefix sums
	// c[0]=p[0]=0; // done by vector
	for(int i=1; i<=N; i++)
	{
		c[i]+=c[i-1];
		p[i]+=p[i-1];
	}

	vector<int> start(N+1), ret(N+1);
	for(int i=1; i<=N; i++)
	{
		//ret[i]=0; // initialization is done by vector
		for(int j=i; j<=N; j++)
		{
			if(d[i]+d[j]+c[j-1]-c[i-1]<=B)
				ret[i]=j;
		}
	}
	for(int i=1; i<=N; i++)
	{
		int length=d[i];
		start[i]=i;
		for(int j=1; j<i; j++)
			if(length>d[j]+c[i-1]-c[j-1])
			{
				length=d[j]+c[i-1]-c[j-1];
				start[i]=j;
			}
	}
// initialization is done by vector
//	for(int i=0; i<=n; i++) dp[0][i]=0;
//	for(int i=0; i<=r; i++) dp[i][n+1]=0;
	for(int i=N; i>0; i--)
	{
		for(int j=1; j<=R; j++)
		{
			if(ret[start[i]]==0) dp[i][j]=dp[i+1][j];
			else dp[i][j]=max(dp[i+1][j],
				dp[ret[start[i]]+1][j-1]+p[ret[start[i]]]-p[i-1]);
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
}

int main()
{
	int nCases;
	scanf("%d",&nCases);
	while(nCases--) solve();
	return 0;
}
