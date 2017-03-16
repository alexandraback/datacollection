#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
    int T, N, P[26];
    scanf("%d", &T);
    for (int c = 0; c < T; ++c) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", P + i);
        }
        printf("Case #%d:", c + 1);
        while (true) {
            int cnt = 0;
            for (int i = 0; i < N; ++i) {
                if (P[i] > 0) ++cnt;
            }
            if (cnt == 0) break;
            printf(" ");
            if (cnt == 2) {
                for (int i = 0; i < N; ++i) {
                    if (P[i] > 0) printf("%c", 'A' + i);
                    --P[i];
                }
            } else {
                int j = 0, maxP = 0;
                for (int i = 0; i < N; ++i) {
                    if (P[i] > maxP) {
                        maxP = P[i];
                        j = i;
                    }
                }
                printf("%c", 'A' + j);
                --P[j];
            }
        }
        printf("\n");
    }
}