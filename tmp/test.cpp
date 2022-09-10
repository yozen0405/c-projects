#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define IO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxn = 1e6 + 5;
int Q[maxn];

int gen (vector<int>& a, int len, int hei) {
	int n = a.size(), cnt = 0, ct = 0;
	set<pii> st;
	int head = 0, tail = 0;
	for (int i = 0; i < n; i++) {
		// 0 1 2 3 4
		// 1 3 2 4 1
		while (head - tail && Q[head] <= i - len) head++;
		while (head - tail && a[Q[tail - 1]] >= a[i]) tail--;
		int mn = min(a[Q[head]], a[i]);
		if (head - tail == 0) mn = a[i];
		Q[tail++] = i;
		if (i >= len - 1) {
			if (mn >= hei) {
				cnt += (mn - hei + 1);
				//cout << "i:" << i <<  ",mn:" << mn << ",cnt:" << mn - hei + 1 << "\n";
			}
		}
	}
	return cnt;
}
/*
5 4
1 3 2 4 1

8 8
3 4 3 3 5 6 3 1
*/

void solve () {
	int n, area;
	vector<int> a;
	cin >> n >> area;
	for (int i = 0, u; i < n; i++) {
		cin >> u;
		a.pb(u);
	}
	int res = 0;
	for (int i = 1; i * i <= area; i++) {
		if (area % i == 0) {
			res += gen(a, i, area / i);
			if (area / i != i) res += gen(a, area / i, i);
		}
	}
	cout << res << "\n";
} 

signed main () {
	IO
	solve();
}
