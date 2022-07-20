#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mk make_pair
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];
int b[maxn];
int n, q;

struct seg1 {
    seg1 *lch, *rch;
    pii val;
    seg1() {
        lch = rch = nullptr;
        val = mk(0, 0);
    }
    void pull () {
        val.first = lch -> val.first + rch -> val.first;;
        val.second = lch -> val.second + rch -> val.second;
    }
    void build(int l, int r) {
        if (l == r) {
            val.first = a[l];
            val.second = a[l] * l;
            return;
        }
        if(!lch) lch = new seg1();
        if(!rch) rch = new seg1();
        int mid = (l + r) >> 1;
        lch -> build(l, mid);
        rch -> build(mid + 1, r);
        pull();
    }
    void modify(int mL, int mR, int l, int r, int v) {
        if (mL <= l && r <= mR) {
            val.first = v;
            val.second = v * l;
            return;
        }
        if(!lch) lch = new seg1();
        if(!rch) rch = new seg1();
        int mid = (l + r) >> 1;
        if (mL <= mid) modify(mL, mR, l, mid, v);
        if(mid < mR) modify(mL, mR, mid + 1, r, v);
        pull();
    }
    pii query(int qL, int qR, int l, int r) {
        if (qL <= l && r <= qR) {
            return val;
        }
        int mid = (l + r) >> 1;
        pii ret = mk(0, 0);
        if (qL <= mid && lch) {
            pii tmp = query(qL, qR, l, mid);
            ret.first += tmp.first;
            ret.second += tmp.second; 
        }
        if (mid + 1 <= qR && rch) {
            pii tmp = query(qL, qR, mid + 1, r);
            ret.first += tmp.first;
            ret.second += tmp.second; 
        }
        return ret;
    }
};

struct seg2 {
    seg2 *lch, *rch;
    pii val;
    seg2() {
        lch = rch = nullptr;
        val = mk(0, 0);
    }
    void pull () {
        val.first = lch -> val.first + rch -> val.first;;
        val.second = lch -> val.second + rch -> val.second;
    }
    void build(int l, int r) {
        if (l == r) {
            val.first = b[l];
            val.second = b[l] * l;
            return;
        }
        if(!lch) lch = new seg2();
        if(!rch) rch = new seg2();
        int mid = (l + r) >> 1;
        lch -> build(l, mid);
        rch -> build(mid + 1, r);
        pull();
    }
    void modify(int mL, int mR, int l, int r, int v) {
        if (mL <= l && r <= mR) {
            val.first = v;
            val.second = v * l;
            return;
        }
        if(!lch) lch = new seg2();
        if(!rch) rch = new seg2();
        int mid = (l + r) >> 1;
        if (mL <= mid) modify(mL, mR, l, mid, v);
        if(mid < mR) modify(mL, mR, mid + 1, r, v);
        pull();
    }
    pii query(int qL, int qR, int l, int r) {
        if (qL <= l && r <= qR) {
            return val;
        }
        int mid = (l + r) >> 1;
        pii ret = mk(0, 0);
        if (qL <= mid && lch) {
            pii tmp = query(qL, qR, l, mid);
            ret.first += tmp.first;
            ret.second += tmp.second; 
        }
        if (mid + 1 <= qR && rch) {
            pii tmp = query(qL, qR, mid + 1, r);
            ret.first += tmp.first;
            ret.second += tmp.second; 
        }
        return ret;
    }
};


signed main () {
    int t;
    while (cin >> t) {
        cin >> n;
        int i, j1, j2;
        for (i = 1, j1 = 0, j2 = 0; i <= n; i++) {
            if(i & 1)
                j1++, cin >> a[j1];
            else 
                j2++, cin >> b[j2];
        }
        seg1 *rt1;
        seg2 *rt2;
        rt1 -> build(1, j1);
        rt2 -> build(1, j2);
        int x, k, l, r;
        char op;
        while (q--) {
            cin >> op;
            if (op == 'U') {
                cin >> x >> k;
                if(x & 1) {
                    rt1 -> modify(1, j1, (l / 2) + 1, (l / 2) + 1, k);
                }
                else {
                    rt2 -> modify(1, j2, l / 2, l / 2, k);
                }
            }
            else {
                cin >> l >> r;
                // a1 * 1 - a2 * 2 + a3 * 3 - a4 * 4
                if(l & 1) {
                    pii ret1 = rt1 -> query(1, j1, (l / 2) + 1, ((r & 1) ? (r / 2) + 1 : ((r - 1) / 2) + 1));
                    pii ret2 = rt2 -> query(1, j2, (l + 1) / 2, ((r & 1) ? ((r - 1) / 2) : (r / 2)));
                    cout << ret1.second - ((l / 2) + 1 - 1) * ret1.first - (ret2.second - (((l + 1) / 2) - 1) * ret2.first);
                }
                else {
                    pii ret1 = rt1 -> query(1, j1, ((l + 1) / 2) + 1, ((r & 1) ? (r / 2) + 1 : ((r - 1) / 2) + 1));
                    pii ret2 = rt2 -> query(1, j2, l / 2, ((r & 1) ? ((r - 1) / 2) : (r / 2)));
                    cout << (ret2.second - ((l  / 2) - 1) * ret2.first) - (ret1.second - (((l + 1) / 2) - 1) * ret1.first);
                }
                cout << "\n";
            }
        }
    }
}

