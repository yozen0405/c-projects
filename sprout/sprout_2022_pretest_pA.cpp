#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#define int long long
#define N 200001
using namespace std;
int n, m, ans = 0, k, arr[N], index;
vector<int> vec;
map<int, int> mp;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    int x, y;
    for (int i = 0;i < k;i++) {
        cin >> y >> x;
        if (y % 2 == 0) {
            vec.push_back((y - 1) * m + m + 1 - x);
            mp[(y - 1) * m + m + 1 - x] = 1;
        }
        else {
            vec.push_back((y - 1) * m + x);
            mp[(y - 1) * m + x] = 1;
        }
    }
    sort(vec.begin(), vec.end());
    int current = 0;
    while (current < n * m) { //index我目前的目標蛇點
        if (index != vec.size()) { //index==vec.size()->要去終點了
            if ((vec[index] - current) % 6 == 0) { //index會不小心跳到連續蛇點的中間
                ans += ((vec[index] - current) / 6);
                current = vec[index]-1;
                for (int i = 0;i < 6;i++) {
                    if (i == 5) {
                        cout << "-1";
                        return 0;
                    }
                    if (!mp[current - i]) { //我這格不是蛇點了
                        current -= i;
                        break;
                    }
                }
            }
            else
                index++;
        }
        else {
            if ((n * m - current) % 6 == 0) ans += ((n * m - current) / 6);
            else ans += ((n*m - current) / 6) + 1; //如果ans距離current是6的倍數那是不是我不用+1
            current = n * m;
        }
    }
    cout << ans;
}
