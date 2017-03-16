#include <bits/stdc++.h>

using namespace std;

const int MAXN = 16 + 3;
const int INF = (int)(1e9);
const int MOD = (int)(1e9) + 7;

int f[MAXN][MAXN * MAXN][(1 << 16) + 10];

int get_bit(int x, int n) {
    return ((x >> n) & 1);
}

int numbits(int x) {
    int res = 0, maxb = 20;
    for(int i = 0; i <= maxb; i++) res += get_bit(x, i);
    return res;
}

int val(int x) {
    int res = 0, maxb = 20, c = 0;
    for(int i = 0; i <= maxb + 1; i++) {
        if (get_bit(x, i) == 0) {
            res += max(0, c - 1);
            c = 0;
        }
        else {
            c++;
        }
    }
    res += max(0, c - 1);
    return res;
}

void minimize(int &a, int b) {
    if (b < a) a = b;
}

int solve() {
    int r, c, n;
    cin >> r >> c >> n;
    for(int i = 0; i <= r; i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k < (1 << c); k++) {
                f[i][j][k] = INF;
            }
        }
    }
    for(int i = 0; i < (1 << c); i++) {
        f[1][numbits(i)][i] = val(i);
    }
    for(int i = 1; i < r; i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k < (1 << c); k++) {
                if (f[i][j][k] == INF) continue;
                for(int t = 0; t < (1 << c); t++) {
                    if (j + numbits(t) <= n) {
                        minimize(f[i + 1][j + numbits(t)][t], f[i][j][k] + numbits(k & t) + val(t));
                    }
                }
            }
        }
    }
    int res = INF;
    for(int i = 0; i < (1 << c); i++) res = min(res, f[r][n][i]);
    return res;
}

int main()
{
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("vuong.out", "w", stdout);

    int test;
    cin >> test;
    for(int tc = 1; tc <= test; tc++) {
        cout << "Case #" << tc << ": " << solve() << endl;
    }
}


