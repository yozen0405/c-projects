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
using P = pair<int, int>;
 
const int INF = 2e18;
const int maxn = 5e5 + 5;
const int M = 1e9 + 7;
const double EPS = 1e-7;

int n, tot;
vector<P> p;
vector<P> a;

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
    cin >> n;
    int x, y;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        p.pb ({x, y});
    }
}

vector<P> convex (vector<P> p){ // wrong 4
    int n = p.size(), m = 0;
    sort(ALL(p));
    vector<P> H;
    for (int t = 0; t < 2; t++) {
        int org = H.size();
        for(int i = 0; i < n; i++) {
            while(m >= org + 2 && 
                    cross(H[m - 1] - H[m - 2],
                        p[i] - H[m - 1]) <= 0) {
                H.pop_back();m--;
            }
            H.pb (p[i]);m++;
        }

        H.pop_back();m--;
        reverse(ALL(p));
    }
    return H;
} 

int onseg (P a, P b, P c) {
    // if c is on Seg(ab)
    if (cross (c - a, c - b) != 0) return 0;

    if (dot (c - a, b - a) < 0) return 0;
    if (dot (c - b, a - b) < 0) return 0;
    return 1;
}

int intersect (P a, P b, P c, P d) {
    int c1 = sign (cross (b - c, d - c)) * sign (cross (a - c, d - c));
    int c2 = sign (cross (d - a, b - a)) * sign (cross (c - a, b - a));

    if (c1 == 1 || c2 == 1) return 0;
    if (c1 == -1 && c2 == -1) return 1;
    if (onseg (a, b, c)) return 1;
    if (onseg (a, b, d)) return 1;
    if (onseg (d, c, a)) return 1;
    if (onseg (d, c, b)) return 1;
    return 0;
}

double disPS (P a, P b, P c) {
    // Seg (a, b) Point (c)
    if (onseg (a, b, c)) return 0;

    double ret = fabs (cross (c - a, b - a)) / len(b - a);
    return ret;
}

int area (vector<P> &p) { // this didn't /2 !!
    int n = p.size ();
    double ret = 0;
    for (int i = 1; i < n; i++) {
        ret += cross (p[i], p[i - 1]);
    }
    ret += cross (p[0], p[n - 1]);
    return abs (ret);
}

P intersection_point (P a, P b, P c, P d) {
    return  c-(d-c)*((double)cross(b-a,c-a)/cross(b-a,d-c));
}

bool cmp(P a, P b) {
    bool f1 = a.x < 0 || (a.x == 0 && a.y < 0) ;
    bool f2 = b.x < 0 || (b.x == 0 && b.y < 0) ;
    if(f1 != f2) return f1 < f2 ;
    return cross(a, b) > 0 ;
}

string print (P a) {
    cout << fixed << setprecision (6) << "(" << a.x << "," << a.y << ")\n";
    return "";
}

string printF (double x) {
    cout << fixed << setprecision (6) << x << "\n";
    return "";
}

int triangle_area (P a, P b, P c) {
    return abs (cross (b - a, c - a));
}
 
void solve () {
    a = convex (p);
    tot = area (a);
    int n = a.size ();

    int c = 1;
    int area = 0, org = INF, ans = INF;
    for (int i = 0; i < n; i++) {
        auto delta = [&] (P A, P B, P C) {
            // AB -> AC
            int F = area + triangle_area (A, B, C);
            int S = tot - F;

            return abs (F - S);
        };

        while (delta (a[i], a[c], a[(c + 1) % n]) < org) {
            org = delta (a[i], a[c], a[(c + 1) % n]);
            area += triangle_area (a[i], a[c], a[(c + 1) % n]);
            c = (c + 1) % n;
        }
        ans = min (ans, org);
        
        area -= triangle_area (a[i], a[(i + 1) % n], a[c]);
        org = abs (area - (tot - area));
    }

    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        init();
        solve(); 
    }
}  
