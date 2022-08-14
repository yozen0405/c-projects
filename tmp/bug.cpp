#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mk make_pair
#define pb push_back
#define x first
#define y second
using namespace std;
using P = pair<long long,long long>;
 
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
 
void solve() {
    int n;
    cin >> n;
    vector<P> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    int ret = 0 ;
    P a = mk(0, 0);
    for (int i = 1; i < n; i++) {
        ret += cross(p[i - 1] - a, p[i] - a);
    }
    ret += cross(p[n - 1] - a, p[0] - a);
    cout << abs(ret);
}
 
signed main () {
    solve();
}
