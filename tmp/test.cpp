#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mk make_pair
#define pb push_back
using namespace std;

const int maxn = 3e3 + 5;
const long long mod = 1e9 + 7;
int n, K;
struct node {
    int x, y, a;
};

// get f(x) = ax + b
int get (pii p, int x) {
    return p.first * x + p.second;
}

int check (pii p, pii p1, pii p2) {
    return (p.second - p1.second) * (p2.first - p.first) <= (p.second - p2.second) * (p1.first - p.first);
    // (b - b1) * (a2 - a) <= (b - b2) * (a1 - a)
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<node> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y >> p[i].a;
    }
    sort (p.begin(), p.end(), [](node a, node b) { if (a.x == b.x) return a.y > b.y; return a.x < b.x;});
    vector<pii> Q(n + 1);
    int head = 0, tail = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        while (tail - head >= 2 && get(Q[head],-p[i].y) <= get(Q[head + 1],-p[i].y)) {
            head++;
        }
        pii cur = {p[i].x, get(Q[head], -p[i].y) + p[i].x * p[i].y - p[i].a};
        while (tail - head >= 2 && check(cur, Q[tail - 1], Q[tail - 2])) {
            tail--;
        }
        Q[tail++] = cur;
        ans = max(Q[tail - 1].second, ans);
    }
    cout << ans;
}
