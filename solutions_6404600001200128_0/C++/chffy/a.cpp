#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

int a[1005];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, tcase = 0;
    scanf("%d", &T);
    while (T--) {
        int n, C = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]), C = max(a[i], (C + 9) / 10);
        int y = 0, z = 1 << 30;
        for (int i = 2; i <= n; ++i)
            if (a[i] < a[i - 1]) y += a[i - 1] - a[i];
        for (int speed = 0; speed <= 10000; ++speed) {
            int i, z0 = 0;
            for (i = 2; i <= n; ++i)
                if (a[i - 1] - speed > a[i]) break;
                else z0 += min(a[i - 1], speed);
            if (i > n) z = min(z, z0);
        }
        printf("Case #%d: %d %d\n", ++tcase, y, z);
    }
    return 0;
}
