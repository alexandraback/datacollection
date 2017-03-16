#include <iostream>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        int n, p[26], s = 0;
        memset(p, 0, sizeof(p));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p[i]);
            s += p[i];
        }
        printf("Case #%d:", ca);
        while (s) {
            printf(" ");
            int mx = -1, m = 0;
            for (int i = 0; i < n; ++i) {
                if (p[i] > m) {
                    m = p[i];
                    mx = i;
                }
            }
            p[mx]--;
            printf("%c", 'A'+mx);
            s--;
            for (int i = 0; i < n; ++i) {
                if (p[i] > s / 2) {
                    p[i]--;
                    s--;
                    printf("%c", 'A'+i);
                    break;
                }
            }
        }
        printf("\n");

    }
    return 0;
}
