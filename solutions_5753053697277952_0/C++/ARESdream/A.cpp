#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int T, n, tt;
int p[maxn];
int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
        printf("Case #%d:", ++tt);
        while (true) {
            printf(" ");
            int sum = 0, id = 0, ma = 0, num = 0;
            for (int i = 1; i <= n; ++i) {
                if (p[i]) {
                    sum += p[i];
                    ++num;
                    if (p[i] > ma) {
                        ma = p[i];
                        id = i;
                    }
                }
            }
            if (sum == 0) break;
            bool ok = true;
            p[id]--;
            for (int i = 1; i <= n; ++i) {
                if (p[i] > (sum - 1) / 2) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                printf("%c", id + 'A' - 1);
                continue;
            }
            p[id]--;
            ok = true;
            for (int i = 1; i <= n; ++i) {
                if (p[i] > (sum - 2) / 2) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                printf("%c%c", id + 'A' - 1, id + 'A' - 1);
                continue;
            }
            p[id] += 2;
            for (int i = 1; i <= n; ++i) {
                if (p[i]) {
                    printf("%c", i + 'A' - 1);
                    p[i]--;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
