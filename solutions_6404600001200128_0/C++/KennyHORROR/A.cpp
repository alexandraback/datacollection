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


int q[10005];

void Solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
    }
    long long s1 = 0, s2 = 0;
    for (int i = 1; i < n; ++i) {
        s1 += max(0, q[i - 1] - q[i]);
    }
    int mx = 0;
    for (int i = 1; i < n; ++i) {
        mx = max(mx, (q[i - 1] - q[i]));
    }
    for (int i = 0; i < n - 1; ++i) {
        s2 += std::min(q[i], mx);
    }
    cout << s1 << " " << s2 << endl;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i + 1);
        Solve();
    }
    return 0;
}
