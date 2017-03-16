#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int T, R, C, N;
int ap[22][22];

int bitcount(int n) {
    int x = 0;
    while (n) {
        x += n & 1;
        n >>= 1;
    }
    return x;
}

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        scanf("%d %d %d", &R, &C, &N);

        int answer = N * 4;
        for (int i = 0; i < (1 << (R * C)); ++i) {
            if (bitcount(i) != N) {
                continue;
            }
            int cur = 0;
            for (int r = 0; r < R; ++r) {
                for (int c = 0; c < C; ++c) {
                    if ((1 << ((r * C) + c)) & i) {
                        ap[r][c] = 1;
                    } else {
                        ap[r][c] = 0;
                    }
                    if (r > 0 && ap[r][c] == 1 && ap[r - 1][c] == 1) {
                        cur++;
                    }
                    if (c > 0 && ap[r][c] == 1 && ap[r][c - 1] == 1) {
                        cur++;
                    }
                }
            }
            answer = min(answer, cur);
        }

        printf("Case #%d: %d\n", t, answer);
    }

    return 0;
}
