#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>

using namespace std;

void precalc() {

}

void solve() {
    int r, c, n;
    cin >> r >> c >> n;

    int k = r * c;
    int ans = 1e9;
    for (int i = 0; i < (1 << k); ++i) {
        int bc = 0;
        for (int j = 1; j <= i; j = j * 2) {
            if (i & j) {
                ++bc;
            }
        }
        if (bc == n) {
            int cur = 0;

            vector< vector<bool> > v(r, vector<bool>(c, false));
            int ic = i;
            for (int b = 0; b <= k; ++b) {
                if (ic & 1) {
                    v[b / c][b % c] = 1;
                }
                ic /= 2;
            }
            for (int x = 0; x < r; ++x) {
                for (int y = 1; y < c; ++y) {
                    if (v[x][y] && v[x][y - 1]) {
                        ++cur;
                    }
                }
            }
            for (int x = 1; x < r; ++x) {
                for (int y = 0; y < c; ++y) {
                    if (v[x][y] && v[x - 1][y]) {
                        ++cur;
                    }
                }
            }
            ans = min(ans, cur);
        }
    }
    cout << ans << endl;
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    precalc();

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cout << "Case #" << test << ": ";
        cerr << test << endl;
        solve();
    }
    return 0;
}
