#ifdef DEBUG
//#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <functional>
#include <complex>

using namespace std;
typedef long double LD;
typedef long long LL;

long long kInf = 1000000000000000000LL;

long long B[10005];

long long cnt(long long t, int b) {
    if (t == -1) {
        return 0;
    }
    long long ret = 0;
    for (int i = 0; i < b; ++i) {
        ret += t / B[i] + 1;
        ret = min(ret, kInf);
    }
    return ret;
}

void Solve() {
    int b, n;
    cin >> b >> n;
    for (int i = 0; i < b; ++i) {
        cin >> B[i];
    }
    long long lb = -1, ub = kInf;
    while (ub - lb > 1) {
        long long mb = (ub + lb) >> 1;
        long long v = cnt(mb, b);
        if (v >= n) {
            ub = mb;
        } else {
            lb = mb;
        }
    }
    long long z = cnt(lb, b);
    ++lb;
    for (int i = 0; i < b; ++i) {
        if (lb % B[i] == 0) {
            ++z;
        }
        if (z == n) {
            cout << i + 1 << endl;
            return;
        }
    }
    cerr << "Very bad\n";
}

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i + 1);
        Solve();
    }
    return 0;
}
