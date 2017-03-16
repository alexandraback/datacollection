#include <cstdio>
#include <algorithm>
using namespace std;

int a[10010];

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas ++) {
        int n;
        scanf("%d", &n);
        int eat1 = 0, eat2 = 0;
        for (int i = 0; i < n; i ++) {
            scanf("%d", &a[i]);
        }
        int gap = 0;
        for (int i = 0; i < n - 1; i ++) {
            if (a[i] > a[i + 1]) {
                gap = max(gap, a[i] - a[i + 1]);
                eat1 += a[i] - a[i + 1];
            }
        }
        for (int i = 0; i < n - 1; i ++) {
            eat2 += min(a[i], gap);
        }
        printf("Case #%d: %d %d\n", cas, eat1, eat2);
    }
    return 0;
}