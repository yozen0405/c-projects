#include <bits/stdc++.h>
#define int long long
#define double long double
#define pii pair<long double, long long>
#define pb push_back
#define mk make_pair
#define x first
#define y second
#define ALL(x) x.begin(), x.end()

using namespace std;
using P = pair<double, double>;
 
const int INF = 2e18;
const int maxn = 5e5 + 5;
const int M = 1e9 + 7;
const double EPS = 1e-7;

double L, a, b, c, p, q;

P operator+ (P a, P b) {
    return {a.x + b.x, a.y + b.y};
};

P operator- (P a, P b) {
    return {a.x - b.x, a.y - b.y};
}

P operator* (P a, double d) {
    return {a.x * d, a.y * d};
}

double cross (P a, P b) {
    return a.x * b.y - a.y * b.x;
}

double dot (P a, P b) {
    return a.x * b.x + a.y * b.y;   
}

double len (P a) {
	return sqrt (dot (a, a));
}

double dis (P a, P b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int sign (double x){
    if (fabs(x) < EPS) return 0;
    else return (x > 0 ? 1 : -1);
}

void init () {
    cin >> L >> a >> b >> c >> p >> q;
}

P intersection_point (P a, P b, P c, P d) {
    return  c-(d-c)*((double)cross(b-a,c-a)/cross(b-a,d-c));
}

vector<P> circle_line_intersection (P a, P b, P c, double r) {
    // line (a, b), circle (c, r)
    P dt = a - b;
    P dn = {-dt.y, dt.x};
    vector<P> ret;

    P m = intersection_point (a, b, c, c + dn);
    if (dis (m, c) == r * r) ret.pb (m);
    else if (dis (m, c) < r * r) {
        double k = (double) sqrt (r * r - dis (m, c)) / len (dt);
        ret.pb (m + dt * k);
        ret.pb (m - dt * k);
    } 

    return ret;
}

pair<P, P> get () {
    if (b == 0) return {{(double) c / a, 0}, {(P){(double) c / a, 0} + (P){0, 1}}};
    if (a == 0) return {{0, (double) c / b}, {(P){0, (double) c / b} + (P){1, 0}}};
    P l1 = {0, (double) c / b};
    P l2 = {(double) c / a, 0};

    return {l1, l2};
}
 
void solve () {
    auto [l1, l2] = get ();
    
    vector<P> ret = circle_line_intersection (l1, l2, (P){0, 0}, L);
    int fg = 0;
    auto check = [&] (double x, double y) {
        double m = atan (x / y);
        if (p <= m && m <= q) {
            cout << fixed << setprecision (12) << m << "\n";
            fg = 1;
        }
    };

    for (auto [x, y] : ret) {
        check (x, y);
        if (fg) return;
    }
}
 
signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        init();
        solve(); 
    }
}  
