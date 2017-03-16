#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stdlib.h>

using namespace std;

int a[20][20];

inline int neig(int i, int j, int r, int c) {
    int res = 0;
    if (i) {
        res += a[i - 1][j];
    }
    if (j) {
        res += a[i][j - 1];
    }
    if (i != r - 1) {
        res += a[i + 1][j];
    }
    if (j != c - 1) {
        res += a[i][j + 1];
    }
    return res;
}

int f(int n, int r, int c) {
    vector<int> m(r * c);
    for (int i = r * c - 1; n > 0; --i, --n) {
        m[i] = 1;
    }
    int opt = r*c*4;
    do {
        for (int i = 0; i < r * c; ++i) {
            int x = i / c;
            int y = i % c;
            a[x][y] = m[i];
        }
        int t = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (a[i][j]) {
                    t += neig(i, j, r, c);
                }
            }
        }
        opt = min(opt, t / 2);
    } while (next_permutation(m.begin(), m.end()));
    return opt;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, r, c;
        scanf("%d%d%d", &r, &c, &n);
        printf("Case #%d: %d\n", i + 1, f(n, r, c));
    }
    return 0;
}
