#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int zz = 1; zz <= t; ++zz) {
        int n;
        scanf("%d", &n);
        vector<int> v(n, 0);
        for (int i = 0; i < n; ++i) scanf("%d", &v[i]);

        int a = 0, r = 0;
        for (int i = 1; i < n; ++i) {
            int d = v[i-1] - v[i];
            if (d > 0) a += d;
            r = max(r, d);
        }
        int b = 0;
        for (int i = 1; i < n; ++i) {
            b += min(v[i-1], r);
        }

        printf("Case #%d: %d %d\n", zz, a, b);
    }

    return 0;
}
