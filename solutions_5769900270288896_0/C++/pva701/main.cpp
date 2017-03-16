#include <iostream>
#include <vector>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
using namespace std;
long long next(long long x) {
    long long n = x;
    vector <int> digits;
    while (x) {
        digits.push_back(x % 10);
        x /= 10;
    }
    sort(digits.begin(), digits.end());
    long long ret = 0;
    for (int i = digits.size() - 1; i >= 0; --i)
        ret = ret * 10 + digits[i];
    if (ret <= n)
        return n + 1;
    return ret;
}
long long next(long long x, long long n) {
    long long nn = n;
    long long xx = x;
    vector <int> digitsx;
    vector <int> digitsn;
    while (x) {
        digitsx.push_back(x % 10);
        x /= 10;
    }

    while (n) {
        digitsn.push_back(n % 10);
        n /= 10;
    }
    reverse(digitsn.begin(), digitsn.end());
    sort(digitsx.begin(), digitsx.end(), greater<int>());
    bool flag = false;
    long long ret = 0;
    for (int i = 0; i < digitsn.size(); ++i) {
        int j = 0;
        while (j < digitsn.size()) {
            long long res = ret * 10 + digitsx[j];
            for (int p = digitsx.size() - 1; p >= 0; --p)
                if (p != j) res = res * 10 + digitsx[p];
            if (res <= nn) break;
            ++j;
        }
        ret = ret * 10 + digitsx[j];
        digitsx.erase(digitsx.begin() + j);
    }
    if (ret <= xx)
        return xx + 1;
    return ret;
}

int len(long long x) {
    int ret = 0;
    while (x) {
        ret++;
        x /= 10;
    }
    return ret;
}

int solve(long long n) {
    cerr << "NOW " << n << endl;
    long long x = 1;
    int ans = 1;
    int lenN = len(n);
    while (len(x) != lenN) {
        x = next(x);
        ++ans;
    }
    //cerr << "x = " << x << endl;
    cerr << "n = " << n << "it = " << n << endl;
    cerr << "x = " << x << endl;
    while (x != n) {
        x = next(x, n);
        //cerr << "nx x = " << x << endl;
        ++ans;
    }
    cerr << "n = " << "it = " << n << endl;
    return ans;
}

int solveB(int r, int c, int n) {
    int tot=1<<(r*c);
    bool a[20][20] = {0};
    const int X[] = {-1, 1, 0, 0};
    const int Y[] = {0, 0, -1, 1};
    int ans = 1e9;
    for (int ms = 0; ms < tot; ++ms) {
        int cnt = 0;
        for (int i = 0; i < r * c; ++i)
            if ((ms>>i)&1) ++cnt;
        if (cnt != n)
            continue;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                a[i][j] = (ms>>(c*i+j))&1;

        int cur = 0;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (a[i][j])
                for (int p = 0; p < 4; ++p) {
                    int ni = i + X[p];
                    int nj = j + Y[p];
                    if (ni >= 0 && nj >= 0 && ni < r && nj < c) cur += a[ni][nj];
                }
        ans = min(ans, cur);
    }
    return ans / 2;
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    long long n;
    for (int i = 1; i <= t; ++i) {
        int r, c, n;
        cin >> r >> c >> n;
        cout << "Case #" << i << ": " << solveB(r, c, n) << endl;
    }
    return 0;
}
