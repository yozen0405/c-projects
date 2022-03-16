#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>>pq;
    for (int i = 0 ; i < m ; i++) pq.push(0);
    int mx = 0;
    for (int i = 0 ; i < n ; i++) {
        int x;
        cin >> x;
        mx = max(mx, pq.top() + x);
        pq.push(pq.top() + x);
        pq.pop();
    }
    cout << mx << '\n';
}
