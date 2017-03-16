#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

typedef long long LL;

struct Point {
    int x, y;

    LL operator * (const Point &a) const {
        return (LL)x * a.y - (LL)a.x * y;
    }

    Point operator - (const Point &a) const {
        return (Point) {x - a.x, y - a.y};
    }

    int operator == (const Point &a) const {
        return make_pair(x, y) == make_pair(a.x, a.y);
    }
}p[3005], a[6005], a0;

int cmp(Point a, Point b) {
    int k1, k2;
    Point aa = a - a0, bb = b - a0;
    if (aa.x > 0 || (aa.x == 0 && aa.y > 0)) k1 = 1;
    else k1 = 2;
    if (bb.x > 0 || (bb.x == 0 && bb.y > 0)) k2 = 1;
    else k2 = 2;
    if (k1 != k2) return k1 < k2;
    return aa * bb < 0;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, tcase = 0;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d%d", &p[i].x, &p[i].y);
        printf("Case #%d:\n", ++tcase);
        for (int i = 1; i <= n; ++i) {
            a0 = p[i];
            int m = 0;
            for (int j = 1; j <= n; ++j)
                if (!(p[j] == a0)) 
                    a[m++] = p[j];
            sort(a, a + m, cmp);
            for (int j = 0; j < m; ++j)
                a[j + m] = a[j];
            int ans = m;
            //if (i == n) printf("%d\n", m);
            for (int j = 0, k = 1; j < m; ++j) {
                while (k < m && (a[k + j] - a0) * (a[j] - a0) >= 0)
                    ++k;
                ans = min(ans, m - k);
                if (k > 1) --k;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
