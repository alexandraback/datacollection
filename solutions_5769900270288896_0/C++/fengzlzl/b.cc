#include <cstdio>

int mat[20][20];

int CountOne(int x) {
    int tot = 0;
    for (; x > 0; x >>= 1)
        if (x&1) tot++;
    return tot;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
            int r, c, n;
        scanf("%d%d%d", &r, &c, &n);
        int m = r * c;
        int best = m * 2;
        for (int st = 0; st < (1 << m); st++) {
            if (CountOne(st) != n) continue;
            //printf("st = %d\n", st);
            for (int i = 0; i < m; i++)
                mat[i / c][i % c] = (st & (1 << i)) ? 1 : 0;
           // for (int i = 0; i < m; i++)  printf("mat[%d][%d]=%d\n", i / c, i % c, mat[i/c][i%c]);
            int tot = 0;
            for (int x = 0; x < r; x++)
                for (int y = 0; y < c; y++) {
                    if (mat[x][y] == 1 && x + 1 < r && mat[x + 1][y] == 1) tot++;
                    if (mat[x][y] == 1 && y + 1 < c && mat[x][y + 1] == 1) tot++;
                }
            if (tot < best) best = tot;
        }
        printf("Case #%d: %d\n", cas, best);
    }
    return 0;
}
