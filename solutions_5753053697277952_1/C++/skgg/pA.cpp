#include <cstdio>

int p[30];

int find_max(int n) {
    int i, ret = 0;
    for (i = 1; i < n; ++i)
        if (p[i] > p[ret])
            ret = i;
    return ret;
}

int main() {
    int T, n, i, a, b, s;
    bool first;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        s = 0;
        printf("Case #%d: ", t);
        scanf("%d", &n);
        for (i = 0; i < n; ++i) {
            scanf("%d", &p[i]);
            s += p[i];
        }
        first = true;
        for (i = 0; i < s; ++i) {
            a = find_max(n);
            --p[a];
            if (first == true) {
                printf("%c", 'A'+a);
                first = false;
            }
            else {
                b = find_max(n);
                if (s-i-1 < p[b] * 2) {
                    printf(" %c", 'A'+a);
                }
                else {
                    if (i == s-1)
                        printf("%c", 'A'+a);
                    else
                        printf("%c ", 'A'+a);
                    first = true;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
