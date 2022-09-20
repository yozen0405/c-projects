#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define pii pair<int, int>
using namespace std;
 
struct qry {
     int idx, val, id, ans;
};

const int INF = 9e18;
const int maxn = 4e6 + 5;
int n, m;
vector<int> a;
vector<qry> q;
int l[maxn], r[maxn], all[maxn], cnt[maxn];

int getPos (vector<int> lis, int x) {
     return lower_bound(lis.begin(), lis.end(), x) - lis.begin();
}

void solve () {
     cin >> n >> m;
     a.resize(n);
     q.resize(m);
     for (int i = 0; i < n; i++) {
          cin >> a[i];
     }     
     for (int i = 0; i < m; i++) {
          cin >> q[i].idx >> q[i].val;
          q[i].idx--;
          q[i].id = i;
     }

     sort (q.begin(), q.end(), [](qry a, qry b) { return a.idx < b.idx; });
     vector<int> lis;
     int len = 0, cur = 0;
     for (int i = 0; i < n; i++) {
          //cout << "cur: " << cur << ",idx:" << q[cur].idx << "\n";
          while (cur < m && q[cur].idx == i) {
               cout << "qL: " << q[cur].idx << ",val:" << getPos(lis, q[cur].val) << "\n";
               q[cur++].ans += getPos(lis, q[cur].val);
          }
          l[i] = getPos(lis, a[i]) + 1;
          // 1 3 4 6
          if (l[i] - 1 < lis.size()) lis[l[i] - 1] = a[i];
          else lis.pb(a[i]);
          len = max(len, l[i]);
          cout << "i:" << i << ",l[i]:" <<  l[i] << "\n";
     }

     // -1 -3 -4 -6
     lis.clear();
     cur = m - 1;
     for (int i = n - 1; i >= 0; i--) {
          while (cur >= 0 && q[cur].idx == i) {
               for (auto ele : lis) cout << -ele << " ";
               cout << "\n";
               cout << "qR: " << q[cur].idx << ",val:" << getPos(lis, -q[cur].val) << "\n";
               q[cur--].ans += getPos(lis, -q[cur].val);
          }
          r[i] = getPos(lis, -a[i]) + 1;
          if (r[i] - 1 < lis.size()) lis[r[i] - 1] = -a[i];
          else lis.pb(-a[i]);
          cout << "i:" << i << ",r[i]:" <<  r[i] << "\n";
     }

     for (int i = 0; i < n; i++) {
          if (l[i] + r[i] - 1 == len) {
               cnt[l[i]]++;
          }
     }
     for (int i = 1; i <= n; i ++) {
          if (l[i] + r[i] - 1 == len) {
               all[i] = (cnt[l[i]] == 1);
               // a[i] 這個位置是不是必要的
               // 如果是必要的那他的 l[i] 這個長度應該只出現一次, only?
          }
     }

     sort (q.begin(), q.end(), [](qry a, qry b) {return a.id < b.id; });
     for (int i = 0; i < m; i++) {
          cout << "val:" << q[i].ans << "\n";
          cout << max(q[i].ans + 1, len - all[q[i].idx]) << "\n";
     }
}
 
signed main () {
     ios::sync_with_stdio(0);
     cin.tie(0);
    solve();
}

/*
15 1
76 9 32 82 40 91 46 5 12 69 44 97 30 13 29
2 62
*/
