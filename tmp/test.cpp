#include <bits/stdc++.h>
#define int long long
#define mk make_pair
#define pii pair<int,int>
using namespace std;

const int maxn = 100010;
const int INF = 0x3f3f3f3f;
int n, q;
int a[maxn];

struct seg {
	seg *lch, *rch;
	int add, ans, flg;
	seg () {
		lch = rch = nullptr;
		ans = add = flg = 0;
	}
	void push(int l, int r) {
		if (add) {
			lch -> add += add;
			rch -> add += add;
			lch -> ans += add;
			rch -> ans += add;
			if(!flg) ans += add;
			add = 0;
			flg = 0;
		}
	}
	void modify(int l, int r, int mL, int mR, int v) {
		if (mL <= l && r <= mR) {
			add += v;
			ans += v;
			flg = 1;
			return;
		}
		int mid = (l + r) >> 1;
		int ret = INF;
		if(!lch) lch = new seg();
		if(!rch) rch = new seg();
		push(l, r);
		if(mL <= mid && lch){
			lch -> modify(l, mid, mL, mR, v);
		} 
		if(mid + 1 <= mR && rch){
			rch -> modify(mid + 1, r, mL, mR, v);
		} 
		ans = ret = min (lch -> ans, rch -> ans);
	}
	int query(int l, int r, int qL, int qR) {
		if (qL <= l && r <= qR) {
			return ans;
		}
		int mid = (l + r) >> 1;
		int ret = INF;
		if(!lch) lch = new seg();
		if(!rch) rch = new seg();
		push(l, r);
		if(qL <= mid && lch) {
			ret = min(ret, lch -> query(l, mid, qL, qR));
		} 
		if(mid + 1 <= qR && rch) {
			ret = min(rch -> query(mid + 1, r, qL, qR), ret);
		} 
		return ret;
	}
};

signed main () {
	cin >> n >> q;
	seg* rt = new seg();
	int op, l, r, x;
	while (q--) {
		cin >> op;
		if (op == 1) {
			cin >> l >> r >> x;
			l++;
			rt -> modify(1, n, l, r, x);
		}
		else {
			cin >> l >> r;
			l++;
			cout << rt -> query(1, n, l, r) << "\n";
		}
	}
}
