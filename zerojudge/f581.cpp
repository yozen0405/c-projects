#include <iostream>
#include <vector>
#include <algorithm>
#define N 200001
#define int long long
using namespace std;
int n, m, p[N];
vector<int> pref; //用array也可以
signed main() {
    cin >> n >> m;
    pref.push_back(0);
    for (int i = 0;i < n;i++) {
        cin >> p[i];
        pref.push_back(pref.back() + p[i]);
    }
    int room = 1, q; //定義room是題目+1，這樣與prefix sum的index相同比較好做
    while (m--) {
        cin >> q; //輸入每輪所需的點數
        q += pref[room - 1]; //要加上之前所到達的全部房間的點數，但不能加上現在所在房間的點數
        q = q % pref[n]; //如果加上去超過了只要把點數再刷新一次
        auto it = lower_bound(pref.begin(), pref.end(), q);//取大於等於點數的prefix sum，it代表現在點數會到達的房間
        room = (it - pref.begin() + 1) ;//-pref.begin()只是為了將iterator換成index，題目要求到了點數和的房間還要再+1
        if (room > n) room = 1;//如果說房間數剛好+1就超過(本來房間已經在邊界值，q又很小，剛好就會超過一間房間)
    }
    cout << room - 1; //我們設定的room是從1開始，所以要-1

}
