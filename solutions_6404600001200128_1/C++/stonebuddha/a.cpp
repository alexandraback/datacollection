#include <cstdio>
#include <algorithm>

using namespace std;

const int kMaxN = 1010;
int n, a[kMaxN];

int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++ kase) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++ i) scanf("%d", &a[i]);
        int res1 = 0;
        for (int i = 1; i < n; ++ i) {
            if (a[i - 1] > a[i]) res1 += a[i - 1] - a[i];
        }
        int res2 = 0;
        int b = max(0, a[0] - a[1]);
        for (int i = 1; i < n - 1; ++ i) 
            b = max(b, a[i] - a[i + 1]);
        int c = a[0];
        for (int i = 0; i < n - 1; ++ i) {
            res2 += min(c, b);
            c = a[i + 1];
        }
        printf("Case #%d: %d %d\n", kase, res1, res2);
    }
    return 0;
}
