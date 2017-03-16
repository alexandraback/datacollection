#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <assert.h>

using namespace std;

int n, m;

vector<int> a;

long long count(long long time) {
    long long res = 0;
    for (int value : a) {
        res += (time / value) + 1;
        if (res > n + m + 1) {
            return res;
        }
    }
    return res;
}

void solve() {
    cin >> m >> n;
    a.clear();
    for (int i = 1; i <= m; i++) {
        int value;
        cin >> value;
        a.push_back(value);
    }
    if (n <= m) {
        printf("%d\n", n);
        return;
    }
    long long l = 0, r = 10000000000000000ll;
    while (l + 1 < r) {
        long long c = (l + r) / 2;
        if (count(c) < n) {
            l = c;
        }
        else {
            r = c;
        }
    }
   // cout << "Time = " << l << endl;
    int numThisSec = n - count(l);
    for (int i = 0; i < m; i++) {
        if ((l + 1) % a[i] == 0) {
            numThisSec--;
            if (numThisSec == 0) {
                printf("%d\n", i + 1);
                return;
            }
        }
    }
    cerr << "CARE!!!" << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    for (int test = 1; test <= tc; test++) {
        printf("Case #%d: ", test);
        solve();
    }
    return 0;
}