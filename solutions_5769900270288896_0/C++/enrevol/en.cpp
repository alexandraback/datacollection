#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool mark[16][16];

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int tt;
    cin >> tt;
    for (int ti = 1; ti <= tt; ++ti) {
        int r, c, n;
        cin >> r >> c >> n;
        int answer = 1234567;
        int t = r * c;
        for (int mask = 0; mask < 1 << t; ++mask) {
            int cnt = __builtin_popcount(mask);
            if (n == cnt) {
                memset(mark, 0, sizeof(mark));
                int u = 0;
                for (int i = 0, k = 0; i < r; ++i)
                    for (int j = 0; j < c; ++j, ++k)
                        if ((mask >> k) & 1) {
                            mark[i][j] = true;
                            if (i > 0) u += mark[i - 1][j];
                            if (j > 0) u += mark[i][j - 1];
                        }
                answer = min(answer, u);
            }
        }
        cout << "Case #" << ti << ": " << answer << '\n';
    }
}
