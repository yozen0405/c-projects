#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define int long long
using namespace std;
int n, m, ans = 0, arr[101][101], tmp[101][101], q;
string str;
signed main() {
    cin >> n >> m >> q;
    int k;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> arr[i][j];
        }
    }
    while (q--) {
        cin >> str >> k;
        if (k == 0) continue;
        if (str == "L") {
            for (int i = 0;i < n;i++)
                for (int j = 0;j < k;j++)
                    arr[i][2 * k - 1 - j] += arr[i][j];
            for (int i = 0;i < n;i++)
                for (int j = 0;j < m;j++)
                    tmp[i][j] = arr[i][j];
            for (int i = 0;i < n;i++)
                for (int j = 0;j < m - k;j++)
                    arr[i][j] = tmp[i][j + k];
            m -= k;
        }
        else if (str == "R") {
            for (int i = 0;i < n;i++)
                for (int j = 0;j < k;j++)
                    arr[i][m - 2 * k + j] += arr[i][m - j - 1];
            m -= k;
        }
        else if (str == "U") {
            for (int j = 0;j < m;j++)
                for (int i = 0;i < k;i++)
                    arr[2 * k - 1 - i][j] += arr[i][j];
            for (int i = 0;i < n;i++)
                for (int j = 0;j < m;j++)
                    tmp[i][j] = arr[i][j];
            for (int i = 0;i < n - k;i++)
                for (int j = 0;j < m;j++)
                    arr[i][j] = tmp[i + k][j];
            n -= k;
        }
        else if (str == "D") {
            for (int j = 0;j < m;j++)
                for (int i = 0;i < k;i++)
                    arr[n - 2 * k + i][j] += arr[n - i - 1][j];
            n -= k;
        }
        else if (str == "LU") {
            for (int p = 0;p < k;p++)
                for (int j = 0, i = 0;j <= p, i <= p;j++, i++) {
                    arr[k - p + i][k - j] += arr[i][p - j];
                    arr[i][p - j] = 0;
                }
        }
        else if (str == "RU") {
            for (int p = 0;p < k;p++)
                for (int j = 0, i = 0;j <= p, i <= p;j++, i++) {
                    arr[k - p + i][m - 1 - k + j] += arr[i][m - 1 - p + j];
                    arr[i][m - 1 - p + j] = 0;
                }
        }
        else if (str == "RD") {
            for (int p = 0;p < k;p++)
                for (int j = 0, i = 0;j <= p, i <= p;j++, i++) {
                    arr[n - 1 - k + i][m - 1 - k + p - j] += arr[n - 1 - p + i][m - 1 - j];
                    arr[n - 1 - p + i][m - 1 - j] = 0;
                }
        }
        else if (str == "LD") {
            for (int p = 0;p < k;p++)
                for (int j = 0, i = 0;j <= p, i <= p;j++, i++) {
                    arr[n - 1 - k + i][k - p + j] += arr[n - 1 - p + i][j];
                    arr[n - 1 - p + i][j] = 0;
                }
        }
    }
    cout <,?< n << " " << m << "\n";
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }


}
