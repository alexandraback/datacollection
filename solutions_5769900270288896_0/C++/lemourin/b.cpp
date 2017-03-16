#include <cstdio>
#include <algorithm>
#define scanf(args...) (scanf(args) ? : 0)
const int MAXN = 100;
const int INF = 1e9;
const int MOVEX[] = { -1, 1, 0, 0 };
const int MOVEY[] = { 0, 0, -1, 1 };

int tab[MAXN][MAXN];

int popcount(unsigned n) {
    return __builtin_popcount(n);
}

int main() {
    int t;
    scanf("%d", &t);

    for (int test=1; test<=t; test++) {
        int r, c, n;
        scanf("%d%d%d", &r, &c, &n);
        
        int res = INF;
        for (unsigned int i=0; i< (1<<(r*c)); i++) {
            if (popcount(i) == n) {
                for (int a=0; a<r; a++)
                    for (int b=0; b<c; b++)
                        tab[a][b] = false;

                for (int j=0; j<r*c; j++) {
                    if ((i & (1 << j)) != 0) {
                        int p = j/c, q = j%c;
                        tab[p][q] = true;
                    }
                }
                
                int current = 0;
                for (int a=0; a<r; a++)
                    for (int b=0; b<c; b++) {
                        if (!tab[a][b])
                            continue;
                        for (int u=0; u<4; u++) {
                            int nr = a+MOVEX[u], nc = b+MOVEY[u];
                            if (nr >= 0 && nr < r && nc >= 0 && nc < c) {
                                if (tab[nr][nc])
                                    current++;
                            }
                        }
                    }
                res = std::min(res, current);
            }
        }
        printf("Case #%d: %d\n", test, res/2);
    }
}
