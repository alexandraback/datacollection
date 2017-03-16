#include <bits/stdc++.h>
using namespace std;

int TC, dp[65540][16][16], R, C, N;

int whack(int bm, int r, int n) {
    if (dp[bm][r][n] != -1) return dp[bm][r][n];
    if (r == R && n == 0) return 0;
    else if (r == R) return 1000000000;
    int mini = 1000000000;
    for (int i = 0; i < (1<<C); i++) {
        int sum = 0, total = 0;
        for (int j = 0; j < C; j++) if (((bm & (1 << j)) > 0) && (((i & (1 << j)) > 0))) sum++;
        for (int j = 0; j < C-1; j++) if ((i & (1 << j)) > 0 && ((i & (1 << (j+1)))) > 0) sum++;
        for (int j = 0; j < C; j++) if ((((i & (1 << j)) > 0))) total++;
        if (total > n) continue;
        mini = min(mini, whack(i, r+1, n-total) + sum);
    }
    return dp[bm][r][n] = mini;
}

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        scanf("%d%d%d", &R, &C, &N);
        memset(dp, -1, sizeof(dp));
        printf("Case #%d: %d\n", tc, whack(0, 0, N));
    }
}
