#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mk make_pair
#define pb push_back
#define x first
#define y second
using namespace std;
using P = pair<long long,long long>;
 
int n;
vector<P> p;

P operator+ (P a, P b) {
    return {a.x + b.x, a.y + b.y};
}
P operator- (P a, P b) {
    return {a.x - b.x, a.y - b.y};
}
P operator* (P a, int d) {
    return {a.x * d, a.y * d};
}
double dot (P a, P b) {
    return a.x * b.x + a.y * b.y;
}
long long cross (P a, P b) {
    return a.x * b.y - a.y * b.x;
}
 
int sign (int x) {
    if (x < 0) return -1;
    if (x > 0) return 1;
    return 0;
}
 
bool oneseg (P a, P b, P c) {
    if (cross(b - a, c - a) != 0) return false;
    if (dot(b - a, c - a) < 0) return false;
    if (dot(a - b, c - b) < 0) return false;
    return true;
}
 
bool insert (P a, P b, P c, P d) {
    int c1 = sign(cross(c - a, b - a)) * sign(cross(d - a, b - a));
    int c2 = sign(cross(b - c, d - c)) * sign(cross(a - c, d - c));
    if (c1 == 1 || c2 == 1) return false;
    if (c1 == -1 && c2 == -1) return true;
    if (oneseg(a, b, c)) return true;
    if (oneseg(a, b, d)) return true;
    if (oneseg(c, d, a)) return true;
    if (oneseg(c, d, b)) return true;
    return false;
}
 
int area(vector<P> &a) {
    int ret = 0 ;
    for (int i = 1; i < a.size(); i++) {
        ret += cross(a[i - 1], a[i]);
    }
    ret += cross(a[a.size()- 1], a[0]);
    return abs(ret);
}

vector<P> convex () {
    sort(p.begin(), p.end(), [](P a, P b){ if(a.x == b.x) return a.y > b.y; return a.x < b.x; });
    vector<int> stk(n);
    vector<int> use(n);
    int tp = 0;
    stk[tp++] = 0;
    for (int i = 1; i < n; i++) {
        while (tp >= 2 && sign(cross(p[stk[tp - 1]] - p[stk[tp - 2]], p[i] - p[stk[tp - 1]])) < 0) {
            use[stk[tp - 1]] = 0;
            tp--;
        }
        use[i] = 1;
        stk[tp++] = i;
    }
    for (int i = n - 2; i >= 0; i--) {
        if(!use[i]) {
            while (tp >= 2 && sign(cross(p[stk[tp - 1]] - p[stk[tp - 2]], p[i] - p[stk[tp - 1]])) < 0) {
                use[stk[tp - 1]] = 0;
                tp--;
            }
            use[i] = 1;
            stk[tp++] = i;
        }
    }
    vector<P> h;
    for (int i = 0; i < tp; i++) {
        h.pb(p[stk[i]]);
    }
    return h;
}

void init() {
	cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
}

void solve() {
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		cnt += __gcd(abs(p[i].x - p[i - 1].x),abs(p[i].y - p[i - 1].y));
	}
	// https://i.imgur.com/vhmXuf5.png
	cnt += __gcd(abs(p[n - 1].x - p[0].x),abs(p[n - 1].y - p[0].y));
	cout << (area(p) - cnt + 2) / 2 << " " << cnt << "\n";
}
 
signed main () {
	init();
	solve();
}
