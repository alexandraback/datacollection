#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main(int argc, char *argv[]) {
    int i, j, t, n, *a, a1, a2, m;
    scanf("%d", &t);
    for (i = 1; i <= t; ++i) {
        scanf("%d", &n);
        a = (int*) malloc(n * sizeof(int));
        for (j = 0; j < n; ++j) {
            scanf("%d", &a[j]);
        }
        a1 = a2 = m = 0;
        for (j = 1; j < n; ++j) {
            if (a[j] - a[j-1] < 0) {
                a1 += (a[j-1]-a[j]);
            }
            m = max(m,a[j-1]-a[j]);
        }
        for (j = 0; j < n - 1; ++j) {
            if (a[j] >= m) {
                a2 += m;
            } else {
                a2 += a[j];
            }
        }
        printf("Case #%d: %d %d\n", i, a1, a2);
    }
    return 0;
}
