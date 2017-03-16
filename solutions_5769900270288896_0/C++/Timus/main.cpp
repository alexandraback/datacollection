#include <iostream>
#include <memory.h>

using namespace std;

int f[17][17];

bool bit(int mask, int i) {
    return (1<<i)&mask;
}

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int getF(int x, int y, int r, int c) {
    if (x < 0 || y < 0 || x >= r || y >= c)
        return 0;
    return f[x][y];
}

int calc(int mask, int r, int c) {
    memset(f, 0, sizeof(f));

    for (int i = 0; i < r * c; ++i) {
        if (bit(mask, i))
            f[i / c][i % c] = 1;
    }

    int ans = 0;

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            if (f[i][j] == 1) {
                for (int k = 0; k < 4; ++k)
                    if (getF(i + dx[k], j + dy[k], r, c) == 1)
                        ++ans;
            }
        }
//    cerr << mask << " " << ans / 2 << endl;
    return ans / 2;
}

int main() {
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int r, c, n;
        cin >> r >> c >> n;
        
        int ans = 1e9;
        for (int mask = 0; mask < (1<<(r * c)); ++mask) {
            int cnt = 0;
            for (int i = 0; i < r * c; ++i)
                cnt += bit(mask, i);
            if (cnt != n) continue;
            ans = min(ans, calc(mask, r, c));
        }

        cout << "Case #" << test << ": " << ans << endl;
    }
}
