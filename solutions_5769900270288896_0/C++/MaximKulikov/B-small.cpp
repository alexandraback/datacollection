#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define PROBLEM "B-small-attempt0"

int w[1 << 16];

void init() {
    int m;
    for (int i = 0; i < (1 << 16); ++i) {
        w[i] = 0;
        for (m = i; m; m &= m-1) ++w[i];
    }
}

int solve(int r, int c, int n) {
    int best = r*c*4;
    int M = 1 << (r*c);
    for (int m = 0; m < M; ++m) {
        if (w[m] == n) {
            int cur = 0;
            //for (int a = m; a; a >>= c) cur += w[a & ((1 << c)-1) & (a >> c)];
            cur += w[(m & (m << c)) & (M-1)];
            for (int i = 0; m >= (1 << i); ++i) {
                if ((i+1)%c != 0) {
                    cur += (((m & (1<<i)) != 0) && ((m & (1<<(i+1))) != 0) ? 1 : 0);
                }
            }
            best = min(best, cur);
        }
    }
    return best;
}

int main() {
    freopen(PROBLEM ".in", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);

    init();

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int r, c, n;
        cin >> r >> c >> n;
        cout << "Case #" << t << ": " << solve(r, c, n) << endl;
    }

    return 0;
}
