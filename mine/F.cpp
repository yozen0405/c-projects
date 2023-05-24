void divide (vector<tuple<int, int, int, int>> &v, int l, int r) {

    if (l >= r) return;

    r -= l, l = 0;

    int mid = (l + r) / 2;

    vector<tuple<int, int, int, int>> vl, vr;

    FOR (i, 0, mid) vl.pb (v[i]);

    FOR (i, mid + 1, v.size() - 1) vr.pb (v[i]);

    v.clear();

    divide (vl, l, mid);

    divide (vr, mid + 1, r);

    int p1 = 0, p2 = 0;

    while (p1 < vl.size() || p2 < vr.size()) {

        int ty;

        if (p2 == vr.size()) ty = 0;

        else if (p1 == vl.size()) ty = 1;

        else if (get<0> (vl[p1]) >= get<0> (vr[p2])) ty = 0;

        else ty = 1;

        if (ty == 0) {

            auto [b, c, t, a] = vl[p1];

            v.pb (vl[p1]);

            p1++;

            if (t == 1) {

                int p = lower_bound (lis.begin(), lis.end(), c) - lis.begin() + 1;

                upd (p, 1);

            }

        } else {

            auto [b, c, t, a] = vr[p2];

            v.pb (vr[p2]);

            p2++;

            if (t == 0) {

                int p = lower_bound (lis.begin(), lis.end(), c) - lis.begin() + 1;

                ans += que (p);

            }

        }

    }

    FOR (i, 0, vl.size() - 1) {

        auto [b, c, t, a] = vl[i];

        if (t == 1) {

            int p = lower_bound (lis.begin(), lis.end(), c) - lis.begin() + 1;

            upd (p, -1);

        }

    }

}

bool ok (int g1, int g2) {

    ans = 0;

    if (g1 == g2) {

        for (auto [a, b, c] : v[g1]) {

            if (min ({a, b, c}) >= money[g1]) ans--;

        }

    }

    vector<tuple<int, int, int, int>> vv;

    int w = money[g1];

    for (auto [a, b, c] : v[g1]) {

        vv.pb (w - b, w - c, 0, w - a);

    }

    w = money[g2];

    lis.clear();

    for (auto [a, b, c] : v[g2]) {

        vv.pb (b - w, c - w, 1, a - w);

        lis.pb (c - w);

    }

    sort (vv.begin(), vv.end(), [] (auto A, auto B) {

        return get<3> (A) != get<3> (B) ? get<3> (A) > get<3> (B) : get<2> (A) > get<2> (B);

    });

    sort (lis.begin(), lis.end());

    lis.erase (unique (lis.begin(), lis.end()), lis.end());

    divide (vv, 0, (int) vv.size() - 1);

    return ans > 0;

}

const int MAX = 1e6;

void solve() {

    cin >> n;

    FOR (t, 1, n) {

        int w, a, b, c;

        int da, db, dc;

        cin >> w >> a >> b >> c;

        int p;

        FOR (i, 0, 2) if (w == money[i]) p = i;

        v[p].pb (a, b, c);

    }

    set<int> s;

    FOR (i, 0, 2) FOR (j, i, 2) {

        if (ok (i, j)) s.insert (money[i] + money[j]);

    }

    cout << s.size() << '\n';

    for (int x : s) cout << x << '\n';

}

int32_t main() {

    Waimai;

    solve();

}
