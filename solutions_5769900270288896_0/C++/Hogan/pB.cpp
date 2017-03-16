#include <cstdio>
#include <cstring>
#include <algorithm>
#include <assert.h>

using namespace std;

bool con[16][16];
int r, c, n;

int dfs(int rr, int cc, int nn) {
    if (rr == r) {
        if (nn) return 100000;

        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (j + 1 < c && con[i][j] == 1 && con[i][j + 1] == 1) ans += 1;
                if (i + 1 < r && con[i][j] == 1 && con[i + 1][j] == 1) ans += 1;
            }
        }
        return ans;
    }

    int nr, nc;
    if (cc == c - 1) {
        nr = rr + 1;
        nc = 0;
    }
    else {
        nr = rr;
        nc = cc + 1;
    }

    int ans = 100000;
    if (nn) {
        con[rr][cc] = 1;
        ans = min(ans, dfs(nr, nc, nn - 1));
    }
    con[rr][cc] = 0;
    ans = min(ans, dfs(nr, nc, nn));

    return ans;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int times = 1; times <= T; times++) {
        scanf("%d%d%d", &r, &c, &n); 
        memset(con, 0, sizeof(con));

        int ans = dfs(0, 0, n);
        printf("Case #%d: %d\n", times, ans);
    }
}
