#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int reduce(int *barbers, int size) {
    int i, t, k = 1, mmc;
    mmc = barbers[0];
    for (i = 1; i < size; ++i) {
        mmc = max(mmc, barbers[i]);
    }
    while (k) {
        t = 0;
        for (i = 0; i < size; ++i) {
            if ((mmc % barbers[i]) != 0) {
                t = 1;
                break;
            }
        }
        ++mmc;
        k = t;
    }
    return --mmc;
}

int main(int argc, char *argv[]) {
    int i, j, pos, resp, T, B, N, *barbers, *counts, m, sum;
    scanf("%d", &T);
    for (i = 0; i < T; ++i) {
        scanf("%d %d", &B, &N);
        barbers = (int *) malloc(B * sizeof(int));
        for (j = 0; j < B; ++j) {
            scanf("%d", &barbers[j]);
        }
        counts = (int *) calloc(B, sizeof(int));
        m = reduce(barbers, B);
        sum = 0;
        for (j = 0; j < B; ++j) {
            sum += m / barbers[j];
        }
        N = N % sum;
        pos = 1;
        resp = -1;
        while (pos <= N) {
            for (j = 0; j < B; ++j) {
                if (counts[j] == 0) {
                    if (pos == N) {
                        resp = j + 1;
                        break;
                    }
                    ++pos;
                }
            }
            if (resp > 0) {
                break;
            }
            m = barbers[0] - counts[0];
            for (j = 1; j < B; ++j) {
                m = min(m, barbers[j]);
            }
            for (j = 0; j < B; ++j) {
                counts[j] += m;
                if (counts[j] == barbers[j]) {
                    counts[j] = 0;
                }
            }
        }
        printf("Case #%d: %d\n", (i + 1), resp < 0 ? B : resp);
    }
    return 0;
}
