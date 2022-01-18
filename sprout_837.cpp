#include <bits/stdc++.h>
#define N 100002
using namespace std;
int arr[N], pref[N], n, m;
int main()
{
    while (cin >> n >> m) {
        for (int i = 1;i <= n;i++) {
            cin >> arr[i];
            pref[i] = pref[i - 1] + arr[i];
        }
        int l, r;
        while (m--) {
            cin >> l >> r;
            cout << pref[r] - pref[l - 1] << "\n";
        }
    }
}
