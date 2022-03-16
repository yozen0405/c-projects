#include <iostream>
#include <algorithm>
using namespace std;
int q, maxi = -1e9, type, c = 0, x, ans;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> q;
	while (q--) {
		cin >> type >> x;
		if (type == 1) {
			if (maxi <= c) {
				ans += x * x;
				maxi = c + x;
			}
			else if (maxi > c + x) {
				ans += 0;
			}
			else {

				ans += x * x - (maxi - c) * (maxi - c);
				maxi = c + x;
			}
		}
		else {
			c += x;
		}

	}
	cout << ans;
}
