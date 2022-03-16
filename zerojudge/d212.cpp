#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#define N 101
using namespace std;
long long w[N],val[2]={1,2},n;
int main() {
    w[1] = 1,w[2]=2;
    for (int j = 3;j <= 100;j++) {
        for (auto i : val)
            w[j] += w[j - i];
    }
    while(cin>>n)
        cout << w[n]<<"\n";
}
