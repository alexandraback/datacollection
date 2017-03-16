#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        int r, c, n;
        scanf("%d%d%d", &r, &c, &n);
        int MASK = 1 << (r * c);
        int ans = r * c * 2;
        for (int x = 0; x < MASK; ++x) {
            if (__builtin_popcount(x) != n) continue;
            bool mat[16][16] = {};
            for (int i = 0, k = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j, ++k) {
                    mat[i][j] = x & 1<<k;
                }
            }
            int cnt = 0;
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    if (!mat[i][j]) continue;
                    if (i + 1 < r && mat[i + 1][j]) ++cnt;
                    if (j + 1 < c && mat[i][j + 1]) ++cnt;
                }
            }
            ans = min(ans, cnt);
        }
        printf("Case #%d: %d\n", cas, ans);
    }
}
