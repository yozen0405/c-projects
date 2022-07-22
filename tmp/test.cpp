#include <bits/stdc++.h>
#define int long long
#define mk make_pair
#define pii pair<int,int>
using namespace std;

const int maxn = 1e5 + 5;
int n, q;
int a[maxn];

struct seg {
	seg *lch, *rch;
	int val;
	seg () {
		lch = rch = nullptr;
		val = 0;
	}
	void pull () {
		val = lch -> val + rch -> val;
	}
	void build (int l, int r) {
		if (l == r) {
			val = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		if(!lch) lch = new seg();
		if(!rch) rch = new seg();
		lch -> build (l, mid);
		rch -> build (mid + 1, r);
		pull();
	}
	void modify(int l, int r, int mL, int mR, int v) {
		if (mL <= l && r <= mR) {
			val = v;
			return;
		}
		int mid = (l + r) >> 1;
		if(!lch) lch = new seg();
		if(!rch) rch = new seg();
		if(mL <= mid && lch) lch -> modify(l, mid, mL, mR, v);
		if(mid + 1 <= mR && rch) rch -> modify(mid + 1, r, mL, mR, v);
		pull();
	}
	int find (int l, int r, int cur) {
		if (l == r) {
			return l;
		}
		int mid = (l + r) >> 1;
		if(lch && cur <= lch -> val) return lch -> find(l, mid, cur);
		else if (rch && lch && cur > lch -> val) return rch -> find(mid + 1, r, cur - lch -> val); 
	}
};

signed main () {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	} 
	seg* rt = new seg();
	rt -> build(1, n);
	int op, idx;
	while (q--) {
		cin >> op >> idx;
		idx++;
		if (op == 1) {
			rt -> modify(1, n, idx, idx, !a[idx]);
		}
		else {
			cout << rt -> find(1, n, idx) - 1 << "\n";
		}
	}
}
