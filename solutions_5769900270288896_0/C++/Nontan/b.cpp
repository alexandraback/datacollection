#include <cstdio>
#include <algorithm>

using namespace std;

int T;
int R, C, N;

int count_1(unsigned x) {
    int r = 0;
    for (int i = 0; i < 16; i++) {
        r += ((x & (1 << i)) ? 1 : 0);
    }
    return r;
}

unsigned bit_n(unsigned x, int i) {
    return (x >> i) & 1;
}

int solve() {
    int ans = 1000000;
    for (unsigned i = 0; i < (1 << (R * C)); i++) {
        if (count_1(i) == N) {
            int u = 0;
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C - 1; k++) {
                    if (bit_n(i, j * C + k) && bit_n(i, j * C + k + 1)) {
                        u++;
                    }
                }
            }

            for (int k = 0; k < C; k++) {
                for (int j = 0; j < R - 1; j++) {
                    if (bit_n(i, j * C + k) && bit_n(i, (j + 1) * C + k)) {
                        u++;
                    }
                }
            }
            ans = min(ans, u);
        }
    }
    return ans;
}

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d%d%d", &R, &C, &N);
        printf("Case #%d: %d\n", i, solve());
    }
}

