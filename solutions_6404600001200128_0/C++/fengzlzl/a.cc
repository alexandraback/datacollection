#include <cstdio>

int a[1010];

int main() {
    int T;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; cas++) {
            int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int first = 0, second = 0;
        int maxdif = 0;
        for (int i = 0; i < n - 1; i++) {
            int dif = a[i] - a[i + 1];
            if (dif > maxdif) maxdif = dif;
            if (dif > 0) first += dif;
        }
        for (int i = 0; i < n - 1; i++) {
            if (a[i] < maxdif) second += a[i];
            else second += maxdif;
        }
        printf("Case #%d: %d %d\n", cas, first, second);
    }
}

