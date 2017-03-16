#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int T, N, B, m[1010], n[1010];

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        scanf("%d %d", &B, &N);
        int prod = 1;
        for (int i = 0; i < B; ++i) {
            scanf("%d", &m[i]);
            prod *= m[i];
            n[i] = 0;
        }
        int tot = 0;
        for (int i = 0; i < B; ++i) {
            tot += prod / m[i];
        }
        N %= tot;
        if (N == 0) {
            N = tot;
        }

        int chose = 0;
        for (int i = 0; i < N; ++i) {
            int best = 0;
            for (int j = 1; j < B; ++j) {
                if (n[j] < n[best]) {
                    best = j;
                }
            }
            chose = best;
            n[best] += m[best];
        }

        printf("Case #%d: %d\n", t, chose + 1);
    }

    return 0;
}
