```cpp
#include<cstdio>
#include<cstring>
#include<algorithm>
#define rd read()
using namespace std;

const int N = 1e6 + 100;

int ans[N], n, m, len, a[N], b[N];

int read() {
    int X = 0, p = 1; char c = getchar();
    for (; c > '9' || c < '0'; c = getchar())
        if (c == '-') p = -1;
    for (; c >= '0' && c <= '9'; c = getchar())
        X = X * 10 + c - '0';
    return X * p;
}

int main()
{
    n = rd;
    for (int i = 1; i <= n; ++i)
        a[i] = rd;
    m = rd;
    for (int i = 1; i <= m; ++i)
        b[i] = rd;
    for (int i = 1, up = max(n, m) + 10; i <= up; ++i) {
        ans[i] += a[i] + b[i];
        if (ans[i] && ans[i - 1])
            ans[i]--, ans[i - 1]--, ans[i + 1]++;
        if (ans[i] > 1) {
            if (i > 1)
                ans[i - 2]++;
            ans[i + 1]++;
            ans[i] -= 2;
        }
    }
    for (int flag = 1; flag;) {
        flag = 0;
        for (int i = max(n, m) + 10; i; --i) {
            if (ans[i] && ans[i - 1])
                flag = 1, ans[i]--, ans[i- 1]--, ans[i + 1]++;
            if (ans[i] > 1)
                flag = 1, ans[i - 2]++, ans[i + 1]++, ans[i] -= 2;
            if (ans[0] && !ans[1])
                ans[1] += ans[0], ans[0] = 0;
        }
    }
    int up = max(n, m) + 10;
    while (!ans[up]) up--;
    printf("%d", up);
    for (int i = 1; i <= up; ++i)
        printf(" %d", ans[i]);
}
```
