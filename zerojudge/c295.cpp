#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#define N 21
using namespace std;
int arr[N][N], max_arr[N], n, m, sum;
int main() {
    cin >> n >> m;
    int a, max_num=-1e9;
    for (int i = 0, k=0;i < n;i++) {
        max_num = -1e9;
        for (int j = 0;j < m;j++) {
            cin >> a;
            max_num = max(a, max_num);
            arr[i][j] = a;
        }
        max_arr[k++] = max_num;
        sum += max_num;
    }
    cout << sum << "\n";
    bool is_output = 0;
    for (int i = 0;i < n;i++) {
            if (sum%max_arr[i]==0) {
                if (is_output) cout << " ";
                cout << max_arr[i];
                is_output = 1;
            }
    }
    if (is_output == 0) cout << "-1";
}
