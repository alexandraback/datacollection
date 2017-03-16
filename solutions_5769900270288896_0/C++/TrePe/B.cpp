#include <stdio.h>

int N, kejs, n, i, j, k;
int rr, cc, nn, cnt, res;
bool p[16];

bool get(int r, int c) {
    if (r >= rr || r < 0 || c < 0 || c >= cc) return false;
    return p[r*cc + c];
}

int main() {
    scanf("%d", &N);
    for (kejs = 1; kejs <= N; kejs++) {
        printf("Case #%d: ", kejs);
        scanf("%d%d%d", &rr, &cc, &n);
        nn = rr * cc;
        res = 1234567890;
        for (i = 0; i < (1 << nn); i++) {
            k = 0;
            for (j = 0; j < nn; j++) {
                if (i & (1 << j)) {
                    p[j] = true;
                    k++;
                } else {
                    p[j] = false;
                }
            }
            if (k == n) {
                cnt = 0;
                for (j = 0; j < rr; j++) {
                    for (k = 0; k < cc; k++) {
                        if (get(j, k)) {
                            cnt += get(j+1, k);
                            cnt += get(j, k+1);
                        }
                    }
                }
                if (res > cnt) {
                    res = cnt;
                    /*
                    printf("%d\n", res);
                    for (j = 0; j < rr; j++) {
                        for (k = 0; k < cc; k++) {
                            putchar(get(j,k) ? 'X' : '.');
                        }
                        putchar('\n');
                    }
                    */
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
