```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

#define int long long
#define x first
#define y second
using pii = pair<int, int>;

int n, A, B, C;
vector<pii> v;
int suma = 0;

void init() {
    cin >> n >> A >> B >> C;

    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        suma += a;      // 假設都全部先選 a[i]
        int x = b - a;  // 改拿 b[i] 可以增加的量
        int y = c - a;  // 改拿 c[i] 可以增加的量
        v[i] = {x, y};
    }
}

int solve() {
    sort(v.rbegin(), v.rend() - 1);  // 按照 x 大到小
                                     //
    vector<int> pre(n + 1);  // pre[i] : v[1~i] 要選出 B 個 x, (i-B) 個 y
    vector<int> suf(n + 1);  // suf[i] : v[i~n] 要選出 B + C - (i-1) 個 y

    // build pre[i]
    priority_queue<int> pq;
    int sum = 0;
    for (int i = 1; i <= B; i++) {
        pq.push(v[i].y - v[i].x);
        sum += v[i].x;
        pre[i] = sum;
    }
    for (int i = B + 1; i <= B + C; i++) {
        pq.push(v[i].y - v[i].x);
        sum += v[i].x;
        sum += pq.top();
        pq.pop();
        pre[i] = sum;
    }

    pq = priority_queue<int>();
    sum = 0;

    // build suf[i]
    for (int i = n; i > B + C; i--) {
        pq.push(v[i].y);
    }
    for (int i = B + C; i > B; i--) {
        pq.push(v[i].y);
        sum += pq.top();
        pq.pop();
        suf[i] = sum;
    }

    // merge pre[] and suf[]
    // pre[i] + suf[i+1] 表示左半全部都要選(當x或當y)，不夠的東西在右邊(suf)選
    int ans = 0;
    for (int i = B; i <= B + C; i++) {
        ans = max(ans, suma + pre[i] + suf[i + 1]);
    }
    return ans;
}

signed main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    int ans = solve();
    cout << ans << '\n';

    return 0;
}
```
