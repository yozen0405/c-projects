```cpp
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define lowbit(x) (x & (-x))
#define F first
#define S second
#define ALL(x) x.begin(), x.end()

using namespace std;
using PQ = priority_queue<int, vector<int>, greater<int>>;
 
const int INF = 2e18;
const int maxn = 3e5 + 5;
const int M = 1e9 + 7;

int n, m, cnt = 0, tot = 0;;
int a[maxn], ans[maxn];

struct query {
	int type, x, y, k, id;
	// 0, l, r, k, qry id
	// 1, index, number, 1/-1 add or del, qry id
};

query q1[2 * maxn], q2[2 * maxn], q[2 * maxn];
query qry[maxn];

struct BIT {
	vector<int> bit;

	void init () {
		bit.resize (n + 1);
	}

	void add (int x, int d) {
		while (x <= n) {
			bit[x] += d;
			x += lowbit (x);
		}
	}

	int query (int x) {
		int ret = 0;
		while (x > 0) {
			ret += bit[x];
			x -= lowbit (x);
		}
		return ret;
	}
} bit;

void divide (int l, int r, int qL, int qR) {
	if (l > r || qL > qR) return;
	if (l == r) {
		//cout << "l:" << l << ",r:" << r << ",mid:" << (l + r)/2 << "\n";
		for (int i = qL; i <= qR; i++) {
			if (q[i].type == 0) {
				ans[q[i].id] = l;
				//cout << "query(" << q[i].x << "," << q[i].y << "," 
			//<< q[i].k << ")\n";
			} 
		}
		return;
	}

	int mid = (l + r) / 2;
	//cout << "l:" << l << ",r:" << r << ",mid:" << (l + r)/2 << "\n";
	int cnt1 = 0, cnt2 = 0;
	for (int i = qL; i <= qR; i++) {
		if (q[i].type == 0) {
			int t = bit.query (q[i].y) - bit.query (q[i].x - 1);
			if (q[i].k <= t) q1[++cnt1] = q[i];
			else q[i].k -= t, q2[++cnt2] = q[i];
			// cout << "t:" << t << "\n";
			// cout << "query(" << q[i].x << "," << q[i].y << "," 
			// << q[i].k << ")\n";
		} 
		else {
			if (q[i].y <= mid) {
				bit.add (q[i].x, q[i].k); // q[i].x
				//cout << "add (" << q[i].x << "," << q[i].k << ")\n";
				q1[++cnt1] = q[i];
			}
			else q2[++cnt2] = q[i];
		}
	}

	// undo
	for (int i = 1; i <= cnt1; i++) 
		if (q1[i].type == 1) {
			bit.add (q1[i].x, -q1[i].k);
			//cout << "del (" << q[i].x << "," << q[i].k << ")\n";
		} 
	for (int i = 1; i <= cnt1; i++) q[qL + i - 1] = q1[i];
	for (int i = 1; i <= cnt2; i++) q[qL + cnt1 + i - 1] = q2[i];

	divide (l, mid, qL, qL + cnt1 - 1);
	divide (mid + 1, r, qL + cnt1, qR);
}

void solve () {
	cin >> n >> m;

	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[i] = x;
		q[++cnt] = {1, i, a[i], 1, -1};
	}
	
	for (int i = 1; i <= m; i++) {
        int x,y,k;
        char type;
        cin >> type;
        if(type=='Q') {
            cin >> x >> y >> k;
            q[++cnt]=(query){0,x,y,k,++tot};
        }
        else {
            cin >> x >> y;
            q[++cnt]=(query){1,x,a[x],-1,0};
            q[++cnt]=(query){1,x,a[x]=y,1,0};
        }
    }

	bit.init ();

	divide (-2e9, 2e9, 1, cnt);

	for (int i = 1; i <= tot; i++) {
		cout << ans[i] << "\n";
	}
} 
 
signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
} 

/*
5 9
3 1 2 4 5
Q 2 2 1
C 3 10
C 2 15
Q 1 4 5
C 5 20
Q 1 5 2
C 1 10
C 2 10
Q 1 4 3
*/
```


```cpp
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define lowbit(x) (x & (-x))
#define F first
#define S second
#define ALL(x) x.begin(), x.end()

using namespace std;
using PQ = priority_queue<int, vector<int>, greater<int>>;
 
const int INF = 2e18;
const int maxn = 3e5 + 5;
const int M = 1e9 + 7;

int n, m, cnt = 0, tot = 0;;
int a[maxn], b[maxn], ans[maxn];

struct query {
	int type, x, y, k, id;
	// 0, l, r, k, qry id
	// 1, index, number, 1/-1 add or del, qry id
};

query q1[2 * maxn], q2[2 * maxn], q[2 * maxn];
query qry[maxn];

struct BIT {
	vector<int> bit;

	void init () {
		bit.resize (n + 1);
	}

	void add (int x, int d) {
		while (x <= n) {
			bit[x] += d;
			x += lowbit (x);
		}
	}

	int query (int x) {
		int ret = 0;
		while (x > 0) {
			ret += bit[x];
			x -= lowbit (x);
		}
		return ret;
	}
} bit;

void divide (int l, int r, int qL, int qR) {
	//cout << "l:" << l << ",r:" << r << "\n";
	if (l > r || qL > qR) return;
	if (l == r) {
		//cout << "l:" << l << ",r:" << r << ",mid:" << (l + r)/2 << "\n";
		for (int i = qL; i <= qR; i++) {
			if (q[i].type == 0) {
				ans[q[i].id] = l;
			// 	cout << "query(" << q[i].x << "," << q[i].y << "," 
			// << q[i].k << ")\n";
			} 
		}
		return;
	}

	int mid = (l + r) / 2;
	//cout << "l:" << l << ",r:" << r << ",mid:" << (l + r)/2 << "\n";
	int cnt1 = 0, cnt2 = 0;
	for (int i = qL; i <= qR; i++) {
		if (q[i].type == 0) {
			int t = bit.query (q[i].y) - bit.query (q[i].x - 1);
			if (q[i].k <= t) q1[++cnt1] = q[i];
			else q[i].k -= t, q2[++cnt2] = q[i];
			// cout << "t:" << t << "\n";
			// cout << "query(" << q[i].x << "," << q[i].y << "," 
			// << q[i].k << ")\n";
		} 
		else {
			if (q[i].y <= mid) {
				bit.add (q[i].x, q[i].k); // q[i].x
				//cout << "add (" << q[i].x << "," << q[i].k << ")\n";
				q1[++cnt1] = q[i];
			}
			else q2[++cnt2] = q[i];
		}
	}

	// undo
	for (int i = 1; i <= cnt1; i++) 
		if (q1[i].type == 1) {
			bit.add (q1[i].x, -q1[i].k);
			//cout << "del (" << q[i].x << "," << q[i].k << ")\n";
		} 
	for (int i = 1; i <= cnt1; i++) q[qL + i - 1] = q1[i];
	for (int i = 1; i <= cnt2; i++) q[qL + cnt1 + i - 1] = q2[i];

	divide (l, mid, qL, qL + cnt1 - 1);
	divide (mid + 1, r, qL + cnt1, qR);
}

void solve () {
	cin >> n >> m;

	vector<int> d;

	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		b[i] = x;
		d.pb (x);
	}

	for (int i = 1; i <= m; i++) {
		char type;
		int x, y, k;

		cin >> type;
		if (type == 'C') {
			cin >> x >> y;
			qry[i] = {1, x, y, -1, -1};
			d.pb (y);
		}
		else {
			cin >> x >> y >> k;
			qry[i] = {0, x, y, k, -1};
		}
	}

	sort (ALL (d));
	d.resize (unique (ALL (d)) - d.begin ());
	int num = d.size ();

	auto get = [&] (int x) {
		return lower_bound (ALL (d), x) - d.begin () + 1;
	};

	for (int i = 1; i <= n; i++) {
		a[i] = get (b[i]);
		//cout << "a[" << i << "]:" << a[i] << "\n";
		q[++cnt] = {1, i, a[i], 1, -1};
	}

	for (int i = 1; i <= m; i++) {
        auto [type, x, y, k, id] = qry[i];

        if(type == 0) {
            q[++cnt]=(query){0,x,y,k,++tot};
        }
        else {
			y = get (y);
            q[++cnt]=(query){1,x,a[x],-1,0};
            q[++cnt]=(query){1,x,a[x]=y,1,0};
        }
    }

	bit.init ();

	divide (1, num, 1, cnt);

	for (int i = 1; i <= tot; i++) {
		cout << d[ans[i] - 1] << "\n";
	}
} 
 
signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
} 

/*
5 9
3 1 2 4 5
Q 2 2 1
C 3 10
C 2 15
Q 1 4 5
C 5 20
Q 1 5 2
C 1 10
C 2 10
Q 1 4 3
*/
```

```cpp
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define lowbit(x) (x & (-x))
#define F first
#define S second
#define ALL(x) x.begin(), x.end()

using namespace std;
using PQ = priority_queue<int, vector<int>, greater<int>>;
 
const int INF = 2e18;
const int maxn = 3e5 + 5;
const int M = 1e9 + 7;

int n, m;
int a[maxn], ans[maxn];

struct query {
	int type, x, y, k, id;
	// 0, l, r, k, qry id
	// 1, index, number, 1/-1 add or del, qry id
};

query q1[2 * maxn], q2[2 * maxn], q[2 * maxn];
query qry[maxn];

struct BIT {
	vector<int> bit;

	void init () {
		bit.resize (n + 1);
	}

	void add (int x, int d) {
		while (x <= n) {
			bit[x] += d;
			x += lowbit (x);
		}
	}

	int query (int x) {
		int ret = 0;
		while (x > 0) {
			ret += bit[x];
			x -= lowbit (x);
		}
		return ret;
	}
} bit;

void divide (int l, int r, int qL, int qR) {
	if (l > r || qL > qR) return;
	if (l == r) {
		//cout << "l:" << l << ",r:" << r << ",mid:" << (l + r)/2 << "\n";
		for (int i = qL; i <= qR; i++) {
			if (q[i].type == 0) {
				ans[q[i].id] = l;
				//cout << "query(" << q[i].x << "," << q[i].y << "," 
			//<< q[i].k << ")\n";
			} 
		}
		return;
	}

	int mid = (l + r) / 2;
	//cout << "l:" << l << ",r:" << r << ",mid:" << (l + r)/2 << "\n";
	int cnt1 = 0, cnt2 = 0;
	for (int i = qL; i <= qR; i++) {
		if (q[i].type == 0) {
			int t = bit.query (q[i].y) - bit.query (q[i].x - 1);
			if (q[i].k <= t) q1[++cnt1] = q[i];
			else q[i].k -= t, q2[++cnt2] = q[i];
			// cout << "t:" << t << "\n";
			// cout << "query(" << q[i].x << "," << q[i].y << "," 
			// << q[i].k << ")\n";
		} 
		else {
			if (q[i].y <= mid) {
				bit.add (q[i].x, q[i].k); // q[i].x
				//cout << "add (" << q[i].x << "," << q[i].k << ")\n";
				q1[++cnt1] = q[i];
			}
			else q2[++cnt2] = q[i];
		}
	}

	// undo
	for (int i = 1; i <= cnt1; i++) 
		if (q1[i].type == 1) {
			bit.add (q1[i].x, -q1[i].k);
			//cout << "del (" << q[i].x << "," << q[i].k << ")\n";
		} 
	for (int i = 1; i <= cnt1; i++) q[qL + i - 1] = q1[i];
	for (int i = 1; i <= cnt2; i++) q[qL + cnt1 + i - 1] = q2[i];

	divide (l, mid, qL, qL + cnt1 - 1);
	divide (mid + 1, r, qL + cnt1, qR);
}

void solve () {
	cin >> n >> m;

	vector<int> b; 
	vector<int> d;
	b.resize (n + 1);
	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		d.pb (x);
		b[i] = x;
	}

	for (int i = 1; i <= m; i++) {
		char type;
		int x, y, k;

		cin >> type;
		if (type == 'C') {
			cin >> x >> y;
			qry[i] = {0, x, y, -1, -1};
			d.pb (y);
		}
		else {
			cin >> x >> y >> k;
			qry[i] = {1, x, y, k, -1};
		}
	}

	sort (ALL (d));
	d.resize (unique (ALL (d)) - d.begin ());

	int num = d.size ();

	//for (auto ele : d) cout << "d:" << ele << "\n";

	for (int i = 1; i <= n; i++) {
		int rk = lower_bound (ALL (d), b[i]) - d.begin ();
		a[i] = rk + 1;
		//cout << "a[" << i << "]:" << a[i] << "\n";
	}

	bit.init ();
	
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		q[++cnt] = {1, i, a[i], 1, -1};
	}

	for (int i = 1; i <= m; i++) {
		auto [type, x, y, k, id] = qry[i];

		if (type == 0) {
			y = lower_bound (ALL (d), y) - d.begin () + 1;
			q[++cnt] = {1, x, a[i], -1, -1};
			a[i] = y;
			q[++cnt] = {1, x, y, 1, -1};
		}
		else {
			q[++cnt] = {0, x, y, k, i};
		}
	}

	divide (1, num, 1, cnt);

	for (int i = 1; i <= m; i++) {
		if (ans[i] == 0) continue;
		
		cout << d[ans[i] - 1] << "\n";
	}
} 
 
signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
} 

/*
5 5
25957 6405 15770 26287 26465 
Q 2 2 1
Q 3 4 1
Q 4 5 1
Q 1 2 2
Q 4 4 1
*/
```
