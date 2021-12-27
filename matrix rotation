#include <iostream>
using namespace std;
int r, c, m, arr[11][11], pref_arr[11][11], m_arr[11];
signed main() {
	while (cin >> r >> c >> m) {
		for (int i = 0;i < r;i++) {
			for (int j = 0;j < c;j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0;i < m;i++) {
			cin >> m_arr[i];
		}
		for (int i = m - 1;i >= 0;i--) {
			if (m_arr[i] == 0) { //旋轉
				for (int i = 0;i < r;i++) {
					for (int j = 0;j < c;j++) {
						pref_arr[i][j] = arr[i][j];
					}
				}
				swap(r, c);
				for (int i = 0;i < r;i++) {
					for (int j = 0;j < c;j++) {
						arr[i][j] = pref_arr[j][r - i - 1];
					}
				}
			}
			else { //翻轉
				for (int i = 0;i < r;i++) {
					for (int j = 0;j < c;j++) {
						pref_arr[i][j] = arr[i][j];
					}
				}
				for (int i = 0;i < r;i++) {
					for (int j = 0;j < c;j++) {
						arr[i][j] = pref_arr[r - i - 1][j];
					}
				}
			}
		}
		cout << r << " " << c << "\n";
		for (int i = 0;i < r;i++) {
			for (int j = 0;j < c;j++) {
				cout << arr[i][j];
				if (j != c - 1) cout << " ";
			}
			cout << "\n";
		}
	}

}
