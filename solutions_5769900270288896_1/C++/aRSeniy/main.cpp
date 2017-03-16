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

int stupid(int r, int c, int n) {
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
    return ans;
}

int smart(int r, int c, int n, int start = 0) {
    int oldn = n;

    vector< vector<bool> > v(r, vector<bool>(c, false));
    for (int i = 0; n && i < r; ++i) {
        for (int j = (i % 2 != start ? 1 : 0); n && j < c; j += 2) {
            v[i][j] = 1;
            --n;
        }
    }

    if (n && !v[0][0]) {
        v[0][0] = 1;
        --n;
    }
    if (n && !v[0][c - 1]) {
        v[0][c - 1] = 1;
        --n;
    }
    if (n && !v[r - 1][0]) {
        v[r - 1][0] = 1;
        --n;
    }
    if (n && !v[r - 1][c - 1]) {
        v[r - 1][c - 1] = 1;
        --n;
    }

    for (int i = 0; n && i < r; ++i)  {
        if (!v[i][0]) {
            v[i][0] = 1;
            --n;
        }
    }
    for (int i = 0; n && i < r; ++i)  {
        if (!v[i][c - 1]) {
            v[i][c - 1] = 1;
            --n;
        }
    }
    for (int j = 0; n && j < c; ++j) {
        if (!v[0][j]) {
            v[0][j] = 1;
            --n;
        }
    }
    for (int j = 0; n && j < c; ++j) {
        if (!v[r - 1][j]) {
            v[r - 1][j] = 1;
            --n;
        }
    }

    for (int i = 0; n && i < r; ++i) {
        for (int j = 0; n && j < c; j++) {
            if (!v[i][j]) {
                v[i][j] = 1;
                --n;
            }
        }
    }

    int ans = 0;
    for (int x = 0; x < r; ++x) {
        for (int y = 1; y < c; ++y) {
            if (v[x][y] && v[x][y - 1]) {
                ++ans;
            }
        }
    }
    for (int x = 1; x < r; ++x) {
        for (int y = 0; y < c; ++y) {
            if (v[x][y] && v[x - 1][y]) {
                ++ans;
            }
        }
    }

    if (start) {
        return ans;
    }
    return min(ans, smart(r, c, oldn, 1));
}

void solve() {
    int r, c, n;
    cin >> r >> c >> n;
    cout << smart(r, c, n) << endl;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    precalc();

    /*for (int r = 1; r < 6; ++r) {
        for (int c = 1; c < 6; ++c) {
            for (int n = 0; n <= r * c; ++n) {
                cerr << r << ' ' << c << ' ' << n << endl;
                if (smart(r, c, n) != stupid(r, c, n)) {
                    cerr << "FUCK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << ' ' << r << ' ' << c << ' ' << n << endl;
                    exit(0);
                }
            }
        }
    }*/
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cout << "Case #" << test << ": ";
        cerr << test << endl;
        solve();
    }
    return 0;
}
